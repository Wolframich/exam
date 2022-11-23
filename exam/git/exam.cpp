#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <Windows.h>

using namespace std;

class Test
{
    int amoundRightAnswers; // amount_right_answers amoundRightAnswers 
public:
    Test() { amoundRightAnswers = 0; }
    int getcount();
    void calculation();
};

int Test::getcount()
{
    return amoundRightAnswers++;
}

void Test::calculation()
{
    int randvalue1;
    int randvalue2;
    int yourvalue;

    for (int i = 0; i < 10; i++)
    {
        cout << "\nЗавдання #" << i + 1 << endl;

        srand(i * time(NULL));
        randvalue1 = rand() % 10;
        randvalue2 = rand() % 10;

        cout << "\t" << randvalue1 << " * " << randvalue2 << " = ";
        cin >> yourvalue;

        if (yourvalue == randvalue1 * randvalue2)
        {
            cout << "Відповідь правильна" << endl;
            cout << "=====================================" << endl;
            getcount();
        }
        else {
            cout << "Відповідь не правильна" << endl;
            cout << "=====================================" << endl;
        }

    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "===Тест на знання таблиці множення===" << endl;
    cout << endl;

    ofstream file;
    string namfile = "Result.tx";

    ifstream ofile;
    string fil;

    string name;
    cout << "\tВведіть ім'я : ";
    cin >> name;

    Test objtest;
    objtest.calculation();

    file.open(namfile, ofstream::app);

    if (file.is_open())
    {
        file <<"\n" << name << " -> вірно " << objtest.getcount() << " з 10." << endl;
    }
    else
    {
        cout << "Помилка!!!";
    }

    file.close();

    
    
    ofile.open(namfile);

    if (ofile.is_open())
    {
        cout << "\n===========Результат тесту===========" << endl;
        while (!ofile.eof())
        {
           
            cout << endl;

            getline(ofile, fil);
            cout << fil;

        }
        cout << endl;
    }
    else
    {
        cout << "Помилка!!!";
    }

    ofile.close();

}

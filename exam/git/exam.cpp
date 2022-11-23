#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

class Test
{
    int a;
public:
    Test() { a = 0; }
    int Getcount();
    void calculation();
};

int Test::Getcount()
{
    return a++;
}

void Test::calculation()
{
        int x;
        int y;
        int z;

        for (int i = 0; i < 10; i++)
        {
            cout << "\nЗавдання #"<<i+1 << endl;

            srand(i * time(NULL));
            x = rand() % 10;
            y = rand() % 10;
           
            cout  <<"\t" << x << " * " << y << " = ";
            cin >> z;

            if (z == x * y)
            {
                cout << "Відповітдь правильна" << endl;
                cout << "=====================================" << endl;
                Getcount();
            }
            else {
                cout << "Відповітдь неправильна" << endl;
                cout << "=====================================" << endl;
            }
        
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
 
    cout << "===Тест на знання таблиці множення==="<<endl;
    cout<<endl;

    ofstream file;
    string namfile = "Result.tx";
    file.exceptions(ofstream::failbit);

    ifstream ofile;
    string fil;
    
    string name;
    cout << "\tВведіть ім'я : " ;
    cin >> name;
   
    Test a;
    a.calculation();

    file.open(namfile);
       
        if (file.is_open())
        {
            file << name << " -> вірно " << a.Getcount() << " з 10.";
        }
        else
        {  
            cout << "Помилка!!!";
        }

    file.close();
  
    ofile.open(namfile);

    if (ofile.is_open())
    {
        cout << "\n===========Результат тесту==========="<<endl;
        while (!ofile.eof())
        {
            fil = "";
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


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include<string>
using namespace std;

class ElectricityBill
{
private:
    int consumerNo;
    string name;
    int units;
    float bill;
    int day, month, year;
public:
    void print_line(char ch, int n)
    {
        for (int i = 0; i < n; i++)
            cout << ch;
        cout << endl;
    }
    void input()
    {
        cout << "Enter Consumer Number: ";
        cin >> consumerNo;
        cin.ignore();
        cout << "Enter Consumer Name: ";
        getline(cin , name);
        cout << "Enter Bill Date (DD MM YYYY): ";
        cin >> day >> month >> year;
        cout << "Enter Units Consumed: ";
        cin >> units;
    }
    void calculate()
    {
        if (units <= 100)
            bill = units * 1.5;
        else if (units <= 300)
            bill = (100 * 1.5) + ((units - 100) * 2.5);
        else
            bill = (100 * 1.5) + (200 * 2.5) + ((units - 300) * 4);
    }
    void display_report()
    {
        print_line('=', 70);
        cout << setw(45) << "ELECTRICITY BILL REPORT" << endl;
        print_line('=', 70);
        cout << "Bill Date   : " << day << "/" << month << "/" << year << endl;
        cout << "Consumer No : " << consumerNo << endl;
        cout << "Name        : " << name << endl;
        print_line('-', 70);
        cout << setw(10) << "S.No"<< setw(25) << "Description"<< setw(20) << "Details" << endl;
        print_line('-', 70);
        cout << setw(10) << 1 << setw(25) << "Units Consumed"<< setw(20) << units << endl;
        cout << setw(10) << 2 << setw(25) << "Bill Amount"<< setw(20) << bill << endl;
        print_line('=', 70);
    }
};
int main()
{
    ElectricityBill e;
    int ch;

    do
    {
        cout << "\n*-- ELECTRICITY BILL MENU --*\n";
        cout << "1. Enter Consumer Details\n";
        cout << "2. Calculate Bill\n";
        cout << "3. Print Bill Report\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            e.input();
            break;
        case 2:
            e.calculate();
            cout << "Bill calculated successfully\n";
            break;
        case 3:
            system("CLS"); 
            e.display_report();
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice\n";
        }
    } while (1);
    return 0;
}

#include<iostream>
#include<iomanip>
using namespace std;

class Demo 
{
    int num;
    float f;

public:
    void input() 
    {
        cout << "Enter integer: ";
        cin >> num;

        cout << "Enter float: ";
        cin >> f;
    }

    void showSetw() 
    {
        cout << "\nsetw():\n";
        cout << setw(10) << num << endl;
    }

    void showSetfill() 
    {
        cout << "\nsetfill():\n";
        cout << setfill('*') << setw(10) << num << endl;
        cout << setfill(' ');
    }

    void showAlignment() 
    {
        cout << "\nleft alignment:\n";
        cout << left << setw(10) << num << endl;

        cout << "right alignment:\n";
        cout << right << setw(10) << num << endl;
    }

    void showPrecision() 
    {
        cout << "\nsetprecision():\n";
        cout << setprecision(3) << f << endl;

        cout << "fixed + setprecision():\n";
        cout << fixed << setprecision(3) << f << endl;
    }

    void showNumberSystem() 
    {
        cout << "\nNumber systems:\n";
        cout << "Decimal: " << dec << num << endl;
        cout << "Hex: " << showbase << hex << num << endl;
        cout << "Octal: " << showbase << oct << num << endl;
    }

    void showEndl() 
    {
        cout << "\nendl demo:\n";
        cout << "Line 1" << endl;
        cout << "Line 2" << endl;
    }
};

int main() 
{
    Demo d;

    d.input();
    d.showSetw();
    d.showSetfill();
    d.showAlignment();
    d.showPrecision();
    d.showNumberSystem();
    d.showEndl();

    return 0;
}
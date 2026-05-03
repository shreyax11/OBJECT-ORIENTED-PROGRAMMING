#include <iostream>
using namespace std;

class ElectricityBill
{
private:
    int units;
    float bill;

public:
    ElectricityBill()
    {
        units = 0;
        bill = 0;
    }
    void input()
    {
        cout << "Enter units: ";
        cin >> units;
    }
    void calculate()
    {
        if (units <= 100)
        {
            bill = units * 1.5;
        }
        else if (units <= 300)
        {
            bill = (100 * 1.5) + ((units - 100) * 2.5);
        }
        else
        {
            bill = (100 * 1.5) + (200 * 2.5) + ((units - 300) * 4);
        }
    }
    void display()
    {
        cout << "Total Bill = " << bill << endl;
    }
};

int main()
{
    ElectricityBill e;
    int choice;
    do
    {
        cout << "\n--- Electricity Bill Menu ---\n";
        cout << "1. Enter Units\n";
        cout << "2. Calculate Bill\n";
        cout << "3. Display Bill\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            e.input();
            break;
        case 2:
            e.calculate();
            cout << "Bill calculated\n";
            break;
        case 3:
            e.display();
            break;
        case 4:
            cout << "Exiting program\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 4);
    return 0;
}

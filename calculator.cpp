#include <iostream>
using namespace std;

class Arithmetic
{
private:
    float a, b;
public:
    void getData()
    {
        cout << "Enter two numbers: ";
        cin >> a >> b;
    }
    void add()
    {
        cout << "Addition = " << a + b << endl;
    }
    void subtract()
    {
        cout << "Subtraction = " << a - b << endl;
    }
    void multiply()
    {
        cout << "Multiplication = " << a * b << endl;
    }
    void divide()
    {
        if (b != 0)
            cout << "Division = " << a / b << endl;
        else
            cout << "Division not possible (divide by zero)" << endl;
    }
};

int main()
{
    Arithmetic obj;
    int choice;

    do
    {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice >= 1 && choice <= 4)
            obj.getData();
        switch (choice)
        {
        case 1:
            obj.add();
            break;
        case 2:
            obj.subtract();
            break;
        case 3:
            obj.multiply();
            break;
        case 4:
            obj.divide();
            break;
        case 5:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);
    return 0;
}

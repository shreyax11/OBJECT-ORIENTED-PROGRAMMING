#include <iostream>
using namespace std;
//using operator overloading
class Complex
{
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }
    void input()
    {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }
    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
    Complex operator+(Complex B)
    {
        return Complex(real + B.real, imag + B.imag);
    }
    Complex operator-(Complex B)
    {
        return Complex(real - B.real, imag - B.imag);
    }
    Complex operator*(Complex B)
    {
        return Complex(
            (real * B.real) - (imag * B.imag),
            (real * B.imag) + (imag * B.real)
        );
    }
};

int main()
{
    Complex A, B, R;
    int choice;
    do
    {
        cout << "\n--- COMPLEX NUMBER MENU ---";
        cout << "\n1. Addition";
        cout << "\n2. Subtraction";
        cout << "\n3. Multiplication";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        if (choice >= 1 && choice <= 3)
        {
            cout << "\nEnter first complex number:\n";
            A.input();
            cout << "Enter second complex number:\n";
            B.input();
            cout << endl;
        }
        switch (choice)
        {
        case 1:
            R = A + B;
            cout << "Addition Result: ";
            R.display();
            break;
        case 2:
            R = A - B;
            cout << "Subtraction Result: ";
            R.display();
            break;
        case 3:
            R = A * B;
            cout << "Multiplication Result: ";
            R.display();
            break;
        case 4:
            cout << "Exit\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 4);
    return 0;
}

#include <iostream>
using namespace std;

template <class T, class U>
class Calculator 
{
    T a;
    U b;
    public:
    Calculator(T x, U y) 
    {
        a = x;
        b = y;
    }

    void display() 
    {
        cout << "Addition: " << a + b << endl;
        cout << "Subtraction: " << a - b << endl;
        cout << "Multiplication: " << a * b << endl;
        cout << "Division: ";
        if(b != 0)
            cout << a / b << endl;
        else 
        cout << "\nError: Division by zero" << endl;
    }
};

int main() 
{
    // int, int
    Calculator<int, int> c1(10, 5);
    c1.display();
    cout << endl;
    // int, float
    Calculator<int, float> c2(10, 2.5);
    c2.display();
    cout << endl;
    // float, float
    Calculator<float, float> c3(2.5, 3.5);
    c3.display();
    return 0;
}
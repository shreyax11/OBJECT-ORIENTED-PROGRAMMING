#include <iostream>
using namespace std;

class Number
{
    int n;
public:
    void input()
    {
        cout << "Enter number: ";
        cin >> n;
    }
    void evenOdd()
    {
        if (n % 2 == 0) cout << "Even\n";
        else cout << "Odd\n";
    }
    void square()
    {
        cout << "Square = " << n * n << endl;
    }
    void cube()
    {
        cout << "Cube = " << n * n * n << endl;
    }
};

int main()
{
    Number obj;
    int ch;

    obj.input();

    cout << "1.Even/Odd 2.Square 3.Cube\n";
    cout << "Enter choice: ";
    cin >> ch;

    switch (ch)
    {
    case 1: 
        obj.evenOdd(); 
        break;
    case 2: 
        obj.square(); 
        break;
    case 3: 
        obj.cube(); 
        break;
    default: 
        cout << "Invalid choice";
    }
}
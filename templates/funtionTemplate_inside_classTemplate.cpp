#include <iostream>
using namespace std;

template <class T>
class Calculator 
{
    T a;

public:
    Calculator(T x)
    {
        a = x;
    }

    // Template function inside class
    template <class U>
    void add(U b) 
    {
        cout << "Addition: " << a + b << endl;
    }
};

int main() 
{
    Calculator<int> c(10);

    c.add(5);      // int
    c.add(2.5);    // float

    return 0;
}
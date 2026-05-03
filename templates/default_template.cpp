#include <iostream>
using namespace std;

//Default type must be from right to left

template <class T = int, class U = float>
class Sample 
{
    T a;
    U b;

    public:
    Sample(T x, U y) 
    {
        a = x;
        b = y;
    }

    void show() 
    {
        cout << "a: " << a << ", b: " << b << endl;
    }
};

int main() {
    Sample<> s1(10, 2.5);        //take it as default value as <>
    Sample<char, int> s2('A', 5);

    s1.show();
    s2.show();
}
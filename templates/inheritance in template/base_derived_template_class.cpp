#include <iostream>
using namespace std;

// Base template
template <class T>
class Base 
{
protected:
    T x;
public:
    void set(T val) 
    {
        x = val;
    }
};

// Derived template
template <class T>
class Derived : public Base<T> 
{
public:
    void show() 
    {
        cout << "Value: " << this->x << endl;
    }
};

int main() 
{
    Derived<int> d1;
    d1.set(10);
    d1.show();

    Derived<float> d2;
    d2.set(5.5);
    d2.show();

    return 0;
}
#include <iostream>
using namespace std;

// Normal base class
class Base 
{
protected:
    int x;
public:
    void set(int val) 
    {
        x = val;
    }
};

// Derived is template
template <class T>
class Derived : public Base 
{
public:
    void show(T y) 
    {
        cout << "Base value: " << x << endl;
        cout << "Derived value: " << y << endl;
    }
};

int main() 
{
    Derived<float> d;
    d.set(10);      
    d.show(5.5);    // Base value will be 10 (int), Derived value will be 5.5 (float)
    //here derived class is template and base class is normal class. 
    //so we can use base class members in derived class 
    //but we cannot use derived class members in base class 
    //because base class is not template and 
    //it does not know about the template parameters of derived class.
}
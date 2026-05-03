#include <iostream>
using namespace std;

template <class T>
class Base 
{
protected:
    T value;

public:
    void set(T v) 
    {
        value = v;
    }
};

class Derived : public Base<int> 
{
public:
    void display()
    {
        cout << "Value: " << value << endl;
    }
};

int main() 
{
    Derived d;
    d.set(10);
    d.display();
    d.set(20.89);  
    // Allowed, but value will be truncated to 20 
    //because Base is instantiated with int in derived class
    d.display();

    return 0;
}
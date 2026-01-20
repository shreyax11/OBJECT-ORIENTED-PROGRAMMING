//umary operator overloading
//post and pre increment and decrement

#include <iostream>
using namespace std;

class Demo {
    int x;

public:
    Demo(int a = 0) 
{
        x = a;
    }

    // PREFIX INCREMENT (++obj)
    Demo operator++() 
    {
        ++x;
        return *this;
    }

    // POSTFIX INCREMENT (obj++)
    Demo operator++(int) 
    {
        Demo temp = *this;   // store old value
        x++;
        return temp;
    }

    // PREFIX DECREMENT (--obj)
    Demo operator--() {
        --x;
        return *this;
    }

    // POSTFIX DECREMENT (obj--)
    Demo operator--(int) {
        Demo temp = *this;   
        x--;
        return temp;
    }

    void display() 
    {
        cout << x << endl;
    }
};

int main() 
{
    Demo d(10);

    cout << "Initial value: ";
    d.display();

    Demo a = ++d;   // prefix ++
    cout << "After a = ++d, d = ";
    d.display();

    Demo b = d++;   // postfix ++
    cout << "After b = d++, d = ";
    d.display();

    Demo c = --d;   // prefix --
    cout << "After c = --d, d = ";
    d.display();

    Demo e = d--;   // postfix --
    cout << "After e = d--, d = ";
    d.display();

    return 0;
}

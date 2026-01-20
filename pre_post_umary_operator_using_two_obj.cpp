//Pre & Post Increment using TWO OBJECTS

#include <iostream>
using namespace std;

class Demo 
{
    int x;

public:
    Demo(int a = 0) 
    {
        x = a;
    }

    // PREFIX INCREMENT (++obj)
    Demo operator++() 
    {
        ++x;           // change calling object
        return *this;  // return updated object
    }
    
    Demo operator--() 
    {
        --x;           
        return *this; 
    }
    
    // POSTFIX INCREMENT (obj++)
    Demo operator++(int) 
    {
        Demo temp = *this; // store old value
        x++;               // change calling object
        return temp;       // return old object
    }
    
    Demo operator--(int) 
    {
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
    Demo d1(10);   // original object
    Demo d2;       // object to store returned value

    cout << "Initial d1 = ";
    d1.display();
    
    // PREFIX
    cout<<"\nPREFIX\n.....\n";
    d2 = ++d1;
    cout << "After \nd2 = ++d1\n";
    cout << "d1 = ";
    d1.display();
    cout << "d2 = ";
    d2.display();
    cout<<".....\n";
    d2 = --d1;
    cout << "After \nd2 = --d1\n";
    cout << "d1 = ";
    d1.display();
    cout << "d2 = ";
    d2.display();
    
    cout<<"\n\nPOSTFIX\n......\n";
    // POSTFIX
    d2 = d1++;
    cout << "After \nd2 = d1++\n";
    cout << "d1 = ";
    d1.display();
    cout << "d2 = ";
    d2.display();
    
    cout<<"......\n";
    
    d2 = d1--;
    cout << "After \nd2 = d1--\n";
    cout << "d1 = ";
    d1.display();
    cout << "d2 = ";
    d2.display();

    return 0;
}

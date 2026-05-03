#include<iostream>
using namespace std;

class Number
{
    int a;
    float b;

public:

    Number(int x=0, float y=0)
    {
        a = x;
        b = y;
    }

    void getData()
    {
        cout<<"Enter integer and float: ";
        cin>>a>>b;
    }

    void showData()
    {
        cout<<"Integer = "<<a<<" Float = "<<b<<endl;
    }

    // + operator overloading
    Number operator+(Number n)
    {
        Number temp;
        temp.a = a + n.a;
        temp.b = b + n.b;
        return temp;
    }

    // Post increment ++ operator
    Number operator++(int)
    {
        Number temp = *this;
        a++;
        b++;
        return temp;
    }
};

int main()
{
    Number n1, n2, n3;

    n1.getData();
    n2.getData();

    n3 = n1 + n2;

    cout<<"After addition:\n";
    n3.showData();

    n1++;

    cout<<"After post increment:\n";
    n1.showData();

    return 0;
}
#include<iostream>
using namespace std;

// Forward declaration
template <class T1, class T2>
void compare(T1, T2);

class A
{
    int x;

public:
    A(int a)
    {
        x = a;
    }

    // friend declaration
    template <class T1, class T2>
    friend void compare(T1, T2);
};

class B
{
    int y;

public:
    B(int b)
    {
        y = b;
    }

    // friend declaration
    template <class T1, class T2>
    friend void compare(T1, T2);
};

// Template function definition
template <class T1, class T2>
void compare(T1 a, T2 b)
{
    if(a.x > b.y)
        cout<<"Object of class A is greater"<<endl;
    else if(a.x < b.y)
        cout<<"Object of class B is greater"<<endl;
    else
        cout<<"Both are equal"<<endl;
}

int main()
{
    A obj1(10);
    B obj2(20);

    compare(obj1, obj2);

    return 0;
}
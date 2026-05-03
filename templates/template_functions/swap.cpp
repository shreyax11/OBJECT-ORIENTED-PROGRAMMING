#include<iostream>
using namespace std;

template <class T>
void swapNum(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 10, y = 20;

    cout<<"Before swap: "<<x<<" "<<y<<endl;
    swapNum(x, y);
    cout<<"After swap: "<<x<<" "<<y<<endl;

    return 0;
}
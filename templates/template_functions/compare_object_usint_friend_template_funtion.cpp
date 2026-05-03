#include<iostream>
using namespace std;

class Test
{
    int x;

public:
    Test(int a)
    {
        x = a;
    }

    // friend template function
    template <class T>
    friend void compare(T a, T b);
};

// Template function
template <class T>
void compare(T a, T b)
{
    if(a.x > b.x)
        cout<<"First object is greater"<<endl;
    else if(a.x < b.x)
        cout<<"Second object is greater"<<endl;
    else
        cout<<"Both are equal"<<endl;
}

int main()
{
    Test t1(10), t2(20);

    compare(t1, t2);

    return 0;
}
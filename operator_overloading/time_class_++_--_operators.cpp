//Implement the Time class for a 24-hour clock. 
//Use a parameterized constructor and overload the pre/post increment and decrement operators.

#include<iostream>
using namespace std;

class Time
{
    int h, m, s;

public:

    // Parameterized constructor
    Time(int hh=0, int mm=0, int ss=0)
    {
        h = hh;
        m = mm;
        s = ss;
    }

    // Display function
    void display()
    {
        cout << h << ":" << m << ":" << s << endl;
    }

    // Pre Increment (++t)
    Time operator++()
    {
        s++;
        if(s == 60)
        {
            s = 0;
            m++;
        }
        if(m == 60)
        {
            m = 0;
            h++;
        }
        if(h == 24)
            h = 0;

        return *this;
    }

    // Post Increment (t++)
    Time operator++(int)
    {
        Time temp = *this;

        s++;
        if(s == 60)
        {
            s = 0;
            m++;
        }
        if(m == 60)
        {
            m = 0;
            h++;
        }
        if(h == 24)
            h = 0;

        return temp;
    }

    // Pre Decrement (--t)
    Time operator--()
    {
        s--;
        if(s < 0)
        {
            s = 59;
            m--;
        }
        if(m < 0)
        {
            m = 59;
            h--;
        }
        if(h < 0)
            h = 23;

        return *this;
    }

    // Post Decrement (t--)
    Time operator--(int)
    {
        Time temp = *this;

        s--;
        if(s < 0)
        {
            s = 59;
            m--;
        }
        if(m < 0)
        {
            m = 59;
            h--;
        }
        if(h < 0)
            h = 23;

        return temp;
    }
};

int main()
{
    Time t1(10, 59, 59);

    cout<<"Original Time: ";
    t1.display();

    ++t1;
    cout<<"After Pre Increment: ";
    t1.display();

    t1++;
    cout<<"After Post Increment: ";
    t1.display();

    --t1;
    cout<<"After Pre Decrement: ";
    t1.display();

    t1--;
    cout<<"After Post Decrement: ";
    t1.display();

    return 0;
}
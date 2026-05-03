#include<iostream>
using namespace std;

class Distance
{
    int meters;

public:

    // Parameterized constructor
    Distance(int m = 0)
    {
        meters = m;
    }

    // >> operator overloading
    friend istream &operator>>(istream &in, Distance &d)
    {
        cout<<"Enter distance in meters: ";
        in>>d.meters;
        return in;
    }

    // << operator overloading
    friend ostream &operator<<(ostream &out, Distance &d)
    {
        out<<"Distance = "<<d.meters<<" meters";
        return out;
    }

    // Friend function to compare two distances
    friend void compare(Distance d1, Distance d2)
    {
        if(d1.meters > d2.meters)
            cout<<"First distance is greater"<<endl;
        else if(d1.meters < d2.meters)
            cout<<"Second distance is greater"<<endl;
        else
            cout<<"Both distances are equal"<<endl;
    }
};

int main()
{
    Distance d1, d2;

    cin>>d1;
    cin>>d2;

    cout<<d1<<endl;
    cout<<d2<<endl;

    compare(d1,d2);

    return 0;
}
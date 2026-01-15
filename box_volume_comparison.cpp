//implementation of a class box , having 3 private member variables
// length l,breath b, height h
//and member functions are 
//getdata(),showdata(),volume(),compare()

// implementation of a class Box having 3 private member variables
// length l, breadth b, height h
// member functions: getdata(), showdata(), volume()
// friend function: compare()

#include <iostream>
#include <cstdlib>
using namespace std;

class Box
{
    int l, b, h;

    int volume()
    {
        return l * b * h;
    }

public:

    void getdata()
    {
        cout << "\nEnter l, b, h respectively: ";
        cin >> l >> b >> h;
    }

    void showdata()
    {
        cout << "l = " << l << endl;
        cout << "b = " << b << endl;
        cout << "h = " << h << endl;
        cout << "Volume = " << volume() << endl;
    }

    friend void compare(Box, Box);
};

void compare(Box b1, Box b2)
{
    if (b1.volume() > b2.volume())
        cout << "Box 1 has greater volume (Volume = " << b1.volume() << ")" << endl;
    else if (b2.volume() > b1.volume())
        cout << "Box 2 has greater volume (Volume = " << b2.volume() << ")" << endl;
    else
        cout << "Both boxes have the same volume" << endl;
}

int main()
{
    Box b1, b2;
    int ch;

    do
    {
        cout << "\n----- BOX MENU -----\n";
        cout << "1. Enter details\n";
        cout << "2. Show data\n";
        cout << "3. Compare volume\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter details of Box 1:";
            b1.getdata();
            cout << "Enter details of Box 2:";
            b2.getdata();
            break;

        case 2:
            cout << "\nBOX 1:\n";
            b1.showdata();
            cout << "\nBOX 2:\n";
            b2.showdata();
            break;

        case 3:
            compare(b1, b2);
            break;

        case 4:
            exit(0);

        default:
            cout << "Invalid choice!";
        }
    } while (1);
}


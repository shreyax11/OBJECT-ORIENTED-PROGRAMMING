/*

Create a program using predefined manipulators that accepts an integer number, a base (like 2, 16, etc.)
and converts the number into that base

Base	Remainder range
2	        0–1
8	        0–7
16	        0–15(after 9, 10-A, 11-B, 12-C, 13-D, 14-E, 15-F)

*/

#include<iostream>
#include<iomanip>
#include<bitset>
using namespace std;

class Convert 
{
public:
    int num;

    Convert(int n) 
    {
        num = n;
    }

    void display(int base) 
    {
        if(base == 2)
            cout << "Binary: " << bitset<32>(num);

        else if(base == 8)
            cout << "Octal: " << oct << num;

        else if(base == 16)
            cout << "Hexadecimal: " << hex << num;

        else
            cout << "Invalid base";
    }
};

int main() 
{
    int num, base;

    cout << "Enter number: ";
    cin >> num;

    cout << "Enter base (2/8/16): ";
    cin >> base;

    Convert c(num);
    c.display(base);

    return 0;
}
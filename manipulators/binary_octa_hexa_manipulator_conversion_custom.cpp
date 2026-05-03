/*

Create a custom manipulator that accepts an integer number, a base (like 2, 16, etc.)
and converts the number into that base

Base	Remainder range
2	        0–1
8	        0–7
16	        0–15(after 9 , 10-A, 11-B, 12-C, 13-D, 14-E, 15-F)

*/
#include<iostream>
using namespace std;

class Convert 
{
public:
    int num, base;

    Convert(int n, int b) 
    {
        num = n;
        base = b;
    }
};

ostream& operator <<(ostream &out, Convert c) 
{
    int n = c.num, base = c.base;
    int arr[20], i = 0;

    if(n==0) 
    {
        out<<0;
        return out;
    }

    while(n>0) 
    {
        arr[i++] = n%base;
        n /= base;
    }

    for(int j = i-1; j >= 0; j--) 
    {
        if(arr[j] < 10)
            out << arr[j];
        else
            out << char(arr[j] - 10 + 'A');
    }

    return out;
}

int main() 
{
    int num;

    cout << "Enter number: ";
    cin >> num;

    cout << "\nBinary: " << Convert(num, 2);
    cout << "\nOctal: " << Convert(num, 8);
    cout << "\nHexadecimal: " << Convert(num, 16);

    return 0;
}
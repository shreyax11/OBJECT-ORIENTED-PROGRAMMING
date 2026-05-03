#include <iostream>
using namespace std;

template <class T, int size>
class Array 
{
    T arr[size];
    int n;   

public:
    Array() 
    {
        n = 0;
    }

    void insert(T value) 
    {
        if(n == size) 
        {
            cout << "Array is full\n";
            return;
        }
        arr[n] = value;
        n++;
        cout << "Inserted\n";
    }

    void deletelast() 
    {
        if(n <= 0) 
        {
            cout << "Array is empty\n";
            return;
        }
        cout << "Deleted: " << arr[n-1] << endl;
        n--;   
        cout << "Last element deleted\n";
    }

    void display() 
    {
        if(n == 0) 
        {
            cout << "Array is empty\n";
            return;
        }

        cout << "Array: ";
        for(int i = 0; i < n; i++) 
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() 
{
    Array<int, 5> a;

    a.insert(10);
    a.insert(20);
    a.insert(30);

    a.display();

    a.deletelast();   
    a.display();

    return 0;
}
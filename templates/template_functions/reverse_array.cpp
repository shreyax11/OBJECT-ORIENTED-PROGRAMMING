#include<iostream>
using namespace std;

template <class T>
void reverseArr(T arr[], int n)
{
    for(int i = 0; i < n/2; i++)
    {
        T temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}

int main()
{
    int a[5] = {1,2,3,4,5};

    reverseArr(a, 5);

    for(int i = 0; i < 5; i++)
        cout<<a[i]<<" ";

    return 0;
}
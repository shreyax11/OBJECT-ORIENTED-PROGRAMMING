#include<iostream>
using namespace std;

template <class T>
T maximum(T arr[], int n)
{
    T max = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main()
{
    int a[5] = {1, 5, 3, 9, 2};
    float b[5] = {1.1, 5.5, 3.3, 9.9, 2.2};

    cout<<"Max (int) = "<<maximum(a, 5)<<endl;
    cout<<"Max (float) = "<<maximum(b, 5)<<endl;

    return 0;
}
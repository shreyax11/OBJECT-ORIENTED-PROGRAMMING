#include<iostream>
using namespace std;

// Template function
template <class T>
T average(T arr[], int n)
{
    T sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum / n;
}

int main()
{
    int n;
    cout<<"Enter size: ";
    cin>>n;

    int a[10];
    float b[10];

    cout<<"Enter integer elements:\n";
    for(int i = 0; i < n; i++)
        cin>>a[i];
    cout<<"Average (int) = "<<average(a, n)<<endl;

    cout<<"Enter float elements:\n";
    for(int i = 0; i < n; i++)
        cin>>b[i];
    cout<<"Average (float) = "<<average(b, n)<<endl;

    return 0;
}
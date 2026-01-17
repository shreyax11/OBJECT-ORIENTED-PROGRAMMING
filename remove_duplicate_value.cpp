#include<iostream>
using namespace std;

// remove duplicate elements from sorted array

int remove_duplicate(int a[],int n)
{
    if(n==0)
        return 0;
    int i=0;
    for(int j=1;j<n;j++)
    {
        if(a[j]!=a[i])
        {
            i++;
            a[i]=a[j];
        }
    }
    return i+1;
}
int main()
{
    int a[]={1,1,2,2,5,6,7};
    int n=sizeof(a)/sizeof(a[0]);
    int newlength = remove_duplicate(a,n);
    cout<<"new non duplicate array is\n";
    for(int i=0;i<newlength;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}

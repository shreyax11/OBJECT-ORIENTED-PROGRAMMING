#include <iostream>
using namespace std;
int main() 
{
    int n;
    cin >> n;
    int arr[100];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int largest = arr[0];
    int second = -1;
    for(int i = 0; i < n; i++) 
    {
        if(arr[i] > largest) 
        {
            second = largest;
            largest = arr[i];
        } 
        else if(arr[i] < largest && arr[i] > second) 
            second = arr[i];
    }
    cout << "Second largest = " << second;
    return 0;
}

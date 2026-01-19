#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int largest = arr[0];
    int smallest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
            largest = arr[i];
        if (arr[i] < smallest)
            smallest = arr[i];
    }
    cout << "Largest element: " << largest << endl;
    cout << "Smallest element: " << smallest << endl;
    return 0;
}
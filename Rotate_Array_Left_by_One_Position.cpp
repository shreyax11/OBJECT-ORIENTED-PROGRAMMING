#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[100];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int temp = arr[0];
    for(int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
    arr[n - 1] = temp;
    cout << "After left rotation:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}

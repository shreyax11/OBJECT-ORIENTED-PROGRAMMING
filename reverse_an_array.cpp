#include<iostream>
using namespace std;
//reverse the aaray
#include <iostream>
using namespace std;
//if we are using stl then we can use this also
//std::reverse(arr.begin(), arr.end());

int main() 
{
    int n = 5;
    int arr[5] = {1, 2, 3, 4, 5};
    int start = 0;
    int end = n - 1;
    while(start < end) 
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    for(int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    return 0;
}

//intersection of two sorted arrays
#include <iostream>
using namespace std;
int main() 
{
    int a[] = {1, 3, 5, 7};
    int b[] = {2, 3, 6, 7};
    int n = 4, m = 4;
    int i = 0, j = 0;
    while(i < n && j < m) 
    {
        if(a[i] < b[j])
            i++;
        else if(a[i] > b[j])
            j++;
        else 
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
    return 0;
}

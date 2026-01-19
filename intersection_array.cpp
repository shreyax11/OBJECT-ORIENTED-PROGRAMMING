// intersection of arrays
#include <iostream>
using namespace std;
int main() 
{
    int a[] = {1, 2, 3, 4};
    int b[] = {3, 4, 5, 6};
    int n = 4, m = 4;
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < m; j++) 
        {
            if(a[i] == b[j]) 
            {
                cout << a[i] << " ";
                break;
            }
        }
    }
    return 0;
}

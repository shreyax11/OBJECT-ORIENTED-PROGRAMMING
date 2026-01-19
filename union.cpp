//union of arrays
#include <iostream>
using namespace std;
int main() 
{
    int a[] = {1, 2, 3, 4};
    int b[] = {3, 4, 5, 6};
    int n = 4, m = 4;
    for(int i = 0; i < n; i++) 
    {
        cout << a[i] << " ";
    }
    for(int i = 0; i < m; i++) 
    {
        bool found = false;
        for(int j = 0; j < n; j++) 
        {
            if(b[i] == a[j]) 
            {
                found = true;
                break;
            }
        }
        if(!found)
            cout << b[i] << " ";
    }
    return 0;
}

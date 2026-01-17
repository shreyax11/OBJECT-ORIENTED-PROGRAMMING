//find the number which is coming only one time in an array using only single loop
//XOR
//xor properties
// n^n=0;
// n^0=n;
#include <iostream>
#include <vector>
using namespace std;
class single_number
{
public:
    int singleNumber(vector<int>& num)
    {
        int ans = 0;
        for (int val : num)
            ans ^= val;
        return ans;
    }
};
int main()
{
    single_number obj;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << "Single number is: " << obj.singleNumber(nums) << endl;
    return 0;
}

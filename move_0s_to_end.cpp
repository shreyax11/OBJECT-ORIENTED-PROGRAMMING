//move 0s to end of array
//[0,1,0,3,12]
#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int j = 0;  // index for non-zero position
    for (int i = 0; i < nums.size(); i++) 
    {
        if (nums[i] != 0) 
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}
int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    for (int x : nums)
        cout << x << " ";
    return 0;
}

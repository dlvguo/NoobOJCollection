#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            //一定注意边界问题
            while (left < nums.size() && nums[left] % 2 == 0)
            {
                left++;
            }

            while (right > -1 && nums[right] % 2)
            {
                right--;
            }
            if (left < right)
                swap(nums[left], nums[right]);
        }
        return nums;
    }
};
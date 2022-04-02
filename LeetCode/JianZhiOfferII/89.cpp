#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums[0];
        int first = nums[0];
        int second = nums[0] > nums[1] ? nums[0] : nums[1];
        for (int i = 2; i < nums.size(); i++)
        {
            int now = max(nums[i] + first, second);
            first = second;
            second = now;
        }
        return max(second, first);
    }
};
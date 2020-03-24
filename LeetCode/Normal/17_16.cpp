#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int massage(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        nums[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            nums[i] = max(nums[i - 2] + nums[i], nums[i - 1]);
        }
        return nums[nums.size() - 1];
    }
};
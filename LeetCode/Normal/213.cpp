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
        int *dp1 = new int[nums.size()];
        int *dp2 = new int[nums.size()];
        dp1[0] = nums[0];
        dp2[0] = 0;
        dp1[1] = dp2[1] = nums[1];
        for (int i = 2; i < nums.size() - 1; i++)
        {
            dp1[i] = max(nums[i] + dp1[i - 2], dp1[i - 1]);
            dp2[i] = max(nums[i] + dp2[i - 2], dp2[i - 1]);
        }
        int i = nums.size() - 1;
        if (i > 1)
        {
            dp2[i]= max(dp2[i-2]+nums[i],dp2[i-1]);
        }

        return max(dp1[i - 1], dp2[i]);
    }
};
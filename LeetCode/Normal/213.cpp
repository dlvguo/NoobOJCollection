#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //要么1-n-1 要么2-n 注意前俩个需要先排下大小
    int massage(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() < 3)
            return max(nums[0], nums[1]);
        int *dp1 = new int[nums.size()];
        int *dp2 = new int[nums.size()];
        dp1[0] = nums[0]; //1-n-1
        dp1[1] = max(nums[1], dp1[0]);
        dp1[2] = max(nums[2] + dp1[0], dp1[1]);
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);
        for (int i = 3; i < nums.size() - 1; i++)
        {
            dp1[i] = max(nums[i] + dp1[i - 2], dp1[i - 1]);
            dp2[i] = max(nums[i] + dp2[i - 2], dp2[i - 1]);
        }
        int i = nums.size() - 1;
        dp2[i] = max(dp2[i - 2] + nums[i], dp2[i - 1]);
        return max(dp1[i - 1], dp2[i]);
    }
};
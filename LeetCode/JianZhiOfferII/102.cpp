#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        //转化为01背包问题
        int sum = 0;
        for (auto num : nums)
            sum += num;
        if (sum < target)
            return 0;
        sum += target;
        if (sum % 2)
            return 0;
        sum /= 2;
        //一维背包
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = sum; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp.back();
    }
};
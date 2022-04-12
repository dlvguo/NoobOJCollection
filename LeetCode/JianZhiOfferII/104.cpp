#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++)
        {
            for (auto num : nums)
            {
                //避免溢出
                if (i >= num && dp[i - num] < INT_MAX - dp[i])
                    dp[i] += dp[i - num];
            }
        }
        return dp.back();
    }
};
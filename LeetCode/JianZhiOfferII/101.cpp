#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            res += nums[i];
        }
        if (res & 1)
            return false;
        res /= 2;
        vector<int> dp(res + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = res; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[res] == res;
    }
};
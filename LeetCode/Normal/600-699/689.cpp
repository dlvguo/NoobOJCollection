#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size(), sum = 0, res = 0, x, y, z;
        vector<int> dp(n), dp1(n), dp2(n);
        for (int i = n - 1; i >= n - k; i--)
        {
            sum += nums[i];
        }
        dp[n - k] = sum;
        for (int i = n - k - 1; i >= 0; i--)
        {
            dp[i] = dp[i + 1] + nums[i] - nums[i + k];
        }
        dp1[k - 1] = 0;
        dp2[n - k] = n - k;
        for (int i = k; i <= n - 1; i++)
        { //结尾
            dp1[i] = dp[i - k + 1] > dp[dp1[i - 1]] ? i - k + 1 : dp1[i - 1];
        }
        for (int i = n - k - 1; i >= 0; i--)
        { //开头
            dp2[i] = dp[i] >= dp[dp2[i + 1]] ? i : dp2[i + 1];
        }
        for (int i = k; i <= n - 2 * k; i++)
        { //遍历第二个下标
            if (dp[dp1[i - 1]] + dp[i] + dp[dp2[i + k]] > res)
            {
                res = dp[dp1[i - 1]] + dp[i] + dp[dp2[i + k]];
                x = dp1[i - 1], y = i, z = dp2[i + k];
            }
        }
        return vector<int>{x, y, z};
    }
};

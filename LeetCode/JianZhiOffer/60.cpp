#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<double> twoSum(int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n * 6 + 1, 0));

        for (int i = 1; i <= 6; i++)
        {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; i++)
        {
            //第n次骰子,最小数为n 类似背包的计算方式
            for (int j = i; j <= n * 6; j++)
            {
                for (int k = 1; k <= 6; k++)
                {
                    if (j - k >= 0)
                    {
                        //注意这里是 +=
                        dp[i][j] += dp[i - 1][j - k];
                    }
                }
            }
        }
        vector<double> ans;
        int total = pow(6, n);
        for (int i = n; i <= n * 6; i++)
        {
            ans.push_back(dp[n][i] * 1.0 / total);
        }
        return ans;
    }
};
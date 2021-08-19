#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static constexpr int MOD = 1'000'000'007;

    int checkRecord(int n)
    {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3))); // 长度，A 的数量，结尾连续 L 的数量
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            // 以 P 结尾的数量
            for (int j = 0; j <= 1; j++)
            {
                for (int k = 0; k <= 2; k++)
                {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % MOD;
                }
            }
            // 以 A 结尾的数量
            for (int k = 0; k <= 2; k++)
            {
                dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][k]) % MOD;
            }
            // 以 L 结尾的数量
            for (int j = 0; j <= 1; j++)
            {
                for (int k = 1; k <= 2; k++)
                {
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
                }
            }
        }
        int sum = 0;
        for (int j = 0; j <= 1; j++)
        {
            for (int k = 0; k <= 2; k++)
            {
                sum = (sum + dp[n][j][k]) % MOD;
            }
        }
        return sum;
    }
};
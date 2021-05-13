#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    const int MODULO = 1000000007;

    int numWays(int steps, int arrLen)
    {
        int maxColumn = min(arrLen - 1, steps);
        vector<vector<int>> dp(steps + 1, vector<int>(maxColumn + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= steps; i++)
        {
            for (int j = 0; j <= maxColumn; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j - 1 >= 0)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MODULO;
                }
                if (j + 1 <= maxColumn)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MODULO;
                }
            }
        }
        return dp[steps][0];
    }
};

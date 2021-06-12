#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string largestNumber(vector<int> &cost, int target)
    {
        vector<vector<int>> dp(10, vector<int>(target + 1, INT_MIN));
        vector<vector<int>> from(10, vector<int>(target + 1));
        dp[0][0] = 0;
        for (int i = 0; i < 9; ++i)
        {
            int c = cost[i];
            for (int j = 0; j <= target; ++j)
            {
                if (j < c)
                {
                    dp[i + 1][j] = dp[i][j];
                    from[i + 1][j] = j;
                }
                else
                {
                    if (dp[i][j] > dp[i + 1][j - c] + 1)
                    {
                        dp[i + 1][j] = dp[i][j];
                        from[i + 1][j] = j;
                    }
                    else
                    {
                        dp[i + 1][j] = dp[i + 1][j - c] + 1;
                        from[i + 1][j] = j - c;
                    }
                }
            }
        }
        if (dp[9][target] < 0)
        {
            return "0";
        }
        string ans;
        int i = 9, j = target;
        while (i > 0)
        {
            if (j == from[i][j])
            {
                --i;
            }
            else
            {
                ans += '0' + i;
                j = from[i][j];
            }
        }
        return ans;
    }
};

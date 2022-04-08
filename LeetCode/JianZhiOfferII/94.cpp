#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minCut(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int r = 0; r < s.size(); r++)
        {
            for (int l = 0; l <= r; l++)
            {
                // 回文串注意判断 中间相等或者间隔1个 因为不像dfs
                if (s[l] == s[r] && (r - l <= 2 || dp[l + 1][r - 1]))
                    dp[l][r] = 1;
            }
        }
        // dp[i]表示1-i
        vector<int> dp2(s.size(), 2002);
        for (int r = 0; r < s.size(); r++)
        {
            //说明是回文串
            if (dp[0][r])
            {
                dp2[r] = 0;
            }
            else
            {
                for (int l = 1; l <= r; l++)
                {
                    if (dp[l][r])
                    {
                        dp2[r] = min(dp2[l - 1] + 1, dp2[r]);
                    }
                }
            }
        }
        return dp2.back();
    }
};
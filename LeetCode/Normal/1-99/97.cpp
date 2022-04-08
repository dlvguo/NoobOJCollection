#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int s1l = s1.size(), s2l = s2.size();
        //注意细节！！！
        if (s1l + s2l != s3.size())
            return false;
        vector<vector<int>> dp(s1l + 1, vector<int>(s2l + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= s1l; ++i)
        {
            for (int j = 0; j <= s2l; ++j)
            {
                int p = i + j - 1;
                if (i > 0)
                {
                    dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[p]);
                }
                if (j > 0)
                {
                    dp[i][j] |= (dp[i][j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }
        return dp.back().back();
    }
};
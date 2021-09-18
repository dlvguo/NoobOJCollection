#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getZerosOnes(string &str)
    {
        vector<int> zerosOnes(2);
        int length = str.length();
        for (int i = 0; i < length; i++)
        {
            zerosOnes[str[i] - '0']++;
        }
        return zerosOnes;
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int length = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i < length; i++)
        {
            vector<int> &&zerosOnes = getZerosOnes(strs[i]);
            int zeros = zerosOnes[0], ones = zerosOnes[1];
            for (int j = m; j >= zeros; j--)
            {
                for (int k = n; k >= ones; k--)
                {
                    dp[j][k] = max(dp[j][k], dp[j - zeros][k - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

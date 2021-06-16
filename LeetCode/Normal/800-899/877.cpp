#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        int length = piles.size();
        auto dp = vector<vector<int>>(length, vector<int>(length));
        for (int i = 0; i < length; i++)
        {
            dp[i][i] = piles[i];
        }
        for (int i = length - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < length; j++)
            {
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][length - 1] > 0;
    }
};

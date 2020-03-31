#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxValue(vector<vector<int>> &grid)
    {
        vector<vector<int>> dp;
        for (int i = 0; i < grid.size(); i++)
        {
            vector<int> v(grid[0].size(), 0);
            dp.push_back(v);
        }
        dp[0][0] = grid[0][0];
        for (int i = 1; i < grid[0].size(); i++)
        {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (j != 0)
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                else
                    dp[i][j] = dp[i - 1][j];
                dp[i][j] += grid[i][j];
            }
        }
        return dp.back().back();
    }
};

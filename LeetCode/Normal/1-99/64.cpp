#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.size() == 0)
            return 0;
        for (int i = 1; i < grid[0].size(); i++)
        {
            grid[0][i] += grid[0][i - 1];
        }
        for (int i = 1; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (!j)
                    grid[i][0] += grid[i - 1][0];
                else
                {
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }
        return grid.back().back();
    }
};
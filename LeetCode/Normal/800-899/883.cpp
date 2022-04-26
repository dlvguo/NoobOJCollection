#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int xyArea = 0, yzArea = 0, zxArea = 0;
        for (int i = 0; i < n; i++)
        {
            int yzHeight = 0, zxHeight = 0;
            for (int j = 0; j < n; j++)
            {
                xyArea += grid[i][j] > 0 ? 1 : 0;
                yzHeight = max(yzHeight, grid[j][i]);
                zxHeight = max(zxHeight, grid[i][j]);
            }
            yzArea += yzHeight;
            zxArea += zxHeight;
        }
        return xyArea + yzArea + zxArea;
    }
};

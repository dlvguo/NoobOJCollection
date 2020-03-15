#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

    int dfs(vector<vector<int>> &grid, int x, int y)
    {
        int sum = 0;
        for (int i = 0; i < 4; i++)
        {
            int _x = x + dir[i][0], _y = y + dir[i][1];
            if (_x < 0 || _x >= grid.size() || _y < 0 || _y >= grid[0].size() || grid[_x][_y] == -1)
                continue;
            if (grid[_x][_y] == 1)
            {
                grid[_x][_y] = -1;
                sum += 1 + dfs(grid, _x, _y);
            }
            else
                grid[_x][_y] = -1;
        }
        return sum;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int sum = 0, max = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = -1;
                    sum = 1 + dfs(grid, i, j);
                    if (max < sum)
                        max = sum;
                }
                else
                {
                    grid[i][j] = -1;
                }
            }
        }
        return max;
    }
};

int main()
{
    Solution s1;
    vector<vector<int>> grids = {{1, 1}, {1, 0}};
    s1.maxAreaOfIsland(grids);
}
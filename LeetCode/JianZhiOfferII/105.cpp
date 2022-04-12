#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    const int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

    int visit[55][55] = {0};
    int m, n;
    int res = 0, temp = 0;

    void dfs(vector<vector<int>> &grid, int x, int y)
    {
        for (int i = 0; i < 4; i++)
        {
            int _x = dir[i][0] + x;
            int _y = dir[i][1] + y;
            if (_x < 0 || _y < 0 || _x >= m || _y >= n || visit[_x][_y] || !grid[_x][_y])
                continue;
            visit[_x][_y] = 1;
            temp++;
            grid[_x][_y] = 0;
            dfs(grid, _x, _y);
        }
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    temp = 1;
                    //注意因为一开始散开 所以必须要赋值
                    visit[i][j] = 1;
                    dfs(grid, i, j);
                    res = max(temp, res);
                }
            }
        return res;
    }
};
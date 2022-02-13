#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    int vis[502][502] = {0};
    void dfs(int x, int y, vector<vector<int>> &grid)
    {
        for (int i = 0; i < 4; i++)
        {
            int _x = x + dir[i][0];
            int _y = y + dir[i][1];
            if (_x < 0 || _y < 0 || _x >= grid.size() || _y >= grid[0].size() || vis[_x][_y])
                continue;
            vis[_x][_y] = 1;
            if (grid[_x][_y])
            {
                grid[_x][_y] = 0;
                dfs(_x, _y, grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int row = grid.size(), col = grid[0].size();
        // 上下
        for (int i = 0; i < col; i++)
        {
            vis[0][i] = 1;
            if (grid[0][i])
            {
                grid[0][i] = 0;
                dfs(0, i, grid);
            }
            if (row > 1)
            {
                vis[row - 1][i] = 1;
                if (grid[row - 1][i])
                {
                    grid[row - 1][i] = 0;
                    dfs(row - 1, i, grid);
                }
            }
        }
        // 左右
        for (int i = 1; i < row - 1; i++)
        {
            vis[i][0] = 1;
            if (grid[i][0])
            {
                vis[i][0] = 1;
                grid[i][0] = 0;
                dfs(i, 0, grid);
            }
            if (col > 1)
            {
                vis[i][col - 1] = 1;
                if (grid[i][col - 1])
                {
                    grid[i][col - 1] = 0;
                    dfs(i, col - 1, grid);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j])
                    res++;
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> grid = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    Solution s;
    cout << s.numEnclaves(grid);
}
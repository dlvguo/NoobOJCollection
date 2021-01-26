#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(vector<vector<int>> &g, int i, int j)
    {
        if (i >= 0 && i < g.size() && j >= 0 && j < g[0].size() && g[i][j] == 0)
        {
            g[i][j] = 1;
            dfs(g, i + 1, j);
            dfs(g, i - 1, j);
            dfs(g, i, j + 1);
            dfs(g, i, j - 1);
        }
    }

    int regionsBySlashes(vector<string> &grid)
    {
        int res = 0;
        vector<vector<int>> g(grid.size() * 3, vector<int>(grid[0].size() * 3, 0));
        // 把1*1的格子看成3*3 根据斜杆将对角线变为1 然后寻找岛屿数量即可
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
            {
                if (grid[i][j] == '/')
                    g[i * 3 + 2][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3][j * 3 + 2] = 1;
                else if (grid[i][j] == '\\')
                    g[i * 3][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3 + 2] = 1;
            }
        }

        for (int i = 0; i < g.size(); i++)
        {
            for (int j = 0; j < g[0].size(); j++)
            {
                if (g[i][j] == 0)
                {
                    dfs(g, i, j);
                    res++;
                }
            }
        }
        return res;
    }
};
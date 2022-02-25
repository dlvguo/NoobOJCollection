#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dfs(vector<vector<int>> &grid, int row, int index)
    {
        if (row == grid.size())
            return index;
        int next = index + grid[row][index];
        if (next < 0 || next >= grid[0].size() || grid[row][index] == 1 && grid[row][next] == -1 || grid[row][index] == -1 && grid[row][next] == 1)
            return -1;
        return dfs(grid, row + 1, next);
    }

    vector<int> findBall(vector<vector<int>> &grid)
    {
        vector<int> res;
        for (int i = 0; i < grid[0].size(); i++)
        {
            res.push_back(dfs(grid, 0, i));
        }
        return res;
    }
};
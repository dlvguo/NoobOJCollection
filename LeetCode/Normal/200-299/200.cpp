#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        for (int i = 0; i < 4; i++)
        {
            int _x = x + dir[i][0], _y = y + dir[i][1];
            if (_x < 0 || _x >= grid.size() || _y < 0 || _y >= grid[0].size() || grid[_x][_y] == '2')
                continue;
            if (grid[_x][_y] == '1')
            {
                grid[_x][_y] = '2';
                dfs(grid, _x, _y);
            }
            else
                grid[_x][_y] = '2';
        }
    }

    int maxAreaOfIsland(vector<vector<char>> &grid)
    {
        int sum = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    grid[i][j] = -1;
                   dfs(grid, i, j);
                    sum++;
                }
                else
                {
                    grid[i][j] = '2';
                }
            }
        }
        return sum;
    }
};

int main()
{
    
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<pair<int, int>> island;
        queue<pair<int, int>> qu;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    qu.emplace(i, j);
                    grid[i][j] = -1;
                    while (!qu.empty())
                    {
                        auto [x, y] = qu.front();
                        qu.pop();
                        island.emplace_back(x, y);
                        for (int k = 0; k < 4; k++)
                        {
                            int nx = x + dirs[k][0];
                            int ny = y + dirs[k][1];
                            if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 1)
                            {
                                qu.emplace(nx, ny);
                                grid[nx][ny] = -1;
                            }
                        }
                    }
                    for (auto &&[x, y] : island)
                    {
                        qu.emplace(x, y);
                    }
                    int step = 0;
                    while (!qu.empty())
                    {
                        int sz = qu.size();
                        for (int i = 0; i < sz; i++)
                        {
                            auto [x, y] = qu.front();
                            qu.pop();
                            for (int k = 0; k < 4; k++)
                            {
                                int nx = x + dirs[k][0];
                                int ny = y + dirs[k][1];
                                if (nx >= 0 && ny >= 0 && nx < n && ny < n)
                                {
                                    if (grid[nx][ny] == 0)
                                    {
                                        qu.emplace(nx, ny);
                                        grid[nx][ny] = -1;
                                    }
                                    else if (grid[nx][ny] == 1)
                                    {
                                        return step;
                                    }
                                }
                            }
                        }
                        step++;
                    }
                }
            }
        }
        return 0;
    }
};

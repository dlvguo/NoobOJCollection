#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        function<void(int, int, int)> dfs = [&](int x, int y, int gold)
        {
            gold += grid[x][y];
            ans = max(ans, gold);

            int rec = grid[x][y];
            grid[x][y] = 0;

            for (int d = 0; d < 4; ++d)
            {
                int nx = x + dirs[d][0];
                int ny = y + dirs[d][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0)
                {
                    dfs(nx, ny, gold);
                }
            }

            grid[x][y] = rec;
        };

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] != 0)
                {
                    dfs(i, j, 0);
                }
            }
        }

        return ans;
    }
};

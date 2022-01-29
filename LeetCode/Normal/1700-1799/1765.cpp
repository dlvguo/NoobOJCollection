#include <bits/stdc++.h>
using namespace std;
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1)); // -1 表示该格子尚未被访问过
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (isWater[i][j])
                {
                    ans[i][j] = 0;
                    q.emplace(i, j); // 将所有水域入队
                }
            }
        }
        while (!q.empty())
        {
            auto &p = q.front();
            for (auto &dir : dirs)
            {
                int x = p.first + dir[0], y = p.second + dir[1];
                if (0 <= x && x < m && 0 <= y && y < n && ans[x][y] == -1)
                {
                    ans[x][y] = ans[p.first][p.second] + 1;
                    q.emplace(x, y);
                }
            }
            q.pop();
        }
        return ans;
    }
};

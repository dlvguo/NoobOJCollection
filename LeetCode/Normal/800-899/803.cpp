#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

class Solution
{
public:
    vector<int> fa, sz, ans;
    int root;
    void init(int n)
    {
        for (int i = 0; i < n; i++)
        {
            fa.push_back(i);
            sz.push_back(1);
        }
    }

    int find(int x)
    {
        if (fa[x] == x)
            return x;
        return fa[x] = find(fa[x]);
    }

    int un(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return 0;
        int ret = 0;
        if (x == find(root))
            ret += sz[y] - 1;
        else if (y == find(root))
            ret += sz[x];
        if (sz[x] >= sz[y])
        {
            sz[x] += sz[y];
            fa[y] = x;
        }
        else
        {
            sz[y] += sz[x];
            fa[x] = y;
        }
        return ret;
    }

    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits)
    {
        int R = grid.size(), C = grid[0].size(), n = R * C + 1;
        root = n - 1;
        // 第一步
        init(n);
        // 第二步
        for (int c = 0; c < C; c++)
            if (grid[0][c])
                un(c, root);
        // 第三步
        for (auto &hit : hits)
        {
            if (grid[hit[0]][hit[1]] == 0)
                hit[0] = -1, hit[1] = -1;
            else
                grid[hit[0]][hit[1]] = 0;
        }

        for (int r = 1; r < R; r++)
        {
            for (int c = 0; c < C; c++)
            {
                if (grid[r][c] == 0)
                    continue;
                for (int k = 0; k < 4; k++)
                {
                    int i = r + dx[k], j = c + dy[k];
                    if (i < 0 || i >= R || j < 0 || j >= C || grid[i][j] == 0)
                        continue;
                    un(i * C + j, r * C + c);
                }
            }
        }
        // 第四步
        reverse(hits.begin(), hits.end());
        for (auto &hit : hits)
        {
            if (hit[0] == -1)
            {
                ans.push_back(0);
                continue;
            }
            int r = hit[0], c = hit[1];
            grid[r][c] = 1;
            int cur = 0;
            for (int k = 0; k < 4; k++)
            {
                int i = r + dx[k], j = c + dy[k];
                if (i < 0 || i >= R || j < 0 || j >= C || grid[i][j] == 0)
                    continue;
                cur += un(i * C + j, r * C + c);
            }
            ans.push_back(cur);
        }
        // 第五步
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

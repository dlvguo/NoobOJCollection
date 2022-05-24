#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int bfs(vector<vector<int>> &forest, int sx, int sy, int tx, int ty)
    {
        if (sx == tx && sy == ty)
        {
            return 0;
        }

        int row = forest.size();
        int col = forest[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        pq.emplace(0, sx * col + sy);
        visited[sx][sy] = true;
        while (!pq.empty())
        {
            auto [dist, loc] = pq.top();
            pq.pop();
            for (int j = 0; j < 4; ++j)
            {
                int nx = loc / col + dirs[j][0];
                int ny = loc % col + dirs[j][1];
                if (nx >= 0 && nx < row && ny >= 0 && ny < col)
                {
                    if (!visited[nx][ny] && forest[nx][ny] > 0)
                    {
                        if (nx == tx && ny == ty)
                        {
                            return dist + 1;
                        }
                        pq.emplace(dist + 1, nx * col + ny);
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        return -1;
    }

    int cutOffTree(vector<vector<int>> &forest)
    {
        vector<pair<int, int>> trees;
        int row = forest.size();
        int col = forest[0].size();
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (forest[i][j] > 1)
                {
                    trees.emplace_back(i, j);
                }
            }
        }
        sort(trees.begin(), trees.end(), [&](const pair<int, int> &a, const pair<int, int> &b)
             { return forest[a.first][a.second] < forest[b.first][b.second]; });

        int cx = 0;
        int cy = 0;
        int ans = 0;
        for (int i = 0; i < trees.size(); ++i)
        {
            int steps = bfs(forest, cx, cy, trees[i].first, trees[i].second);
            if (steps == -1)
            {
                return -1;
            }
            ans += steps;
            cx = trees[i].first;
            cy = trees[i].second;
        }
        return ans;
    }
};

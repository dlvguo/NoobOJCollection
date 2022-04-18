#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int visit[202][202] = {0};
    const int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

    int dfs(int x, int y, vector<vector<int>> &matrix)
    {
        if (visit[x][y])
            return visit[x][y];
        visit[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int _x = dir[i][0] + x, _y = dir[i][1] + y;
            if (_x < 0 || _y < 0 || _x >= matrix.size() || _y >= matrix[0].size())
                continue;
            if (matrix[_x][_y] > matrix[x][y])
                visit[x][y] = max(visit[x][y], dfs(_x, _y, matrix) + 1);
        }
        return visit[x][y];
    }

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int _max = 1;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
            {
                _max = max(_max, dfs(i, j, matrix));
            }
        return _max;
    }
};
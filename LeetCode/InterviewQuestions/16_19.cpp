#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dir[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};

    int dfs(vector<vector<int>> &land, int x, int y)
    {
        // 进来就代表0能进来吧
        int res = 1;
        land[x][y] = 1;
        for (int i = 0; i < 8; i++)
        {
            int _x = x + dir[i][0], _y = y + dir[i][1];
            if (_x < 0 || _x == land.size() || _y < 0 || _y == land[0].size() || land[_x][_y])
                continue;
            res += dfs(land, _x, _y);
        }
        return res;
    }

    vector<int> pondSizes(vector<vector<int>> &land)
    {
        vector<int> res;
        for (int i = 0; i < land.size(); i++)
            for (int j = 0; j < land[0].size(); j++)
            {
                if (!land[i][j])
                    res.push_back(dfs(land, i, j));
            }
        sort(res.begin(), res.end());
        return res;
    }
};
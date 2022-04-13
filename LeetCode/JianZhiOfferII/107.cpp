#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    const int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        queue<pair<int, int>> pq;
        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (!mat[i][j])
                {
                    pq.push({i, j});
                    mat[i][j] = -1;
                }
            }
        int cen = 1;
        while (pq.size())
        {
            cen++;
            int num = pq.size();
            while (num--)
            {
                auto f = pq.front();
                pq.pop();
                for (int i = 0; i < 4; i++)
                {
                    int _x = f.first + dir[i][0], _y = f.second + dir[i][1];
                    if (_x < 0 || _y < 0 || _x >= mat.size() || _y >= mat[0].size() || mat[_x][_y] < 0)
                        continue;
                    mat[_x][_y] = -cen;
                    pq.push({_x, _y});
                }
            }
        }
        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[0].size(); j++)
                mat[i][j] = -mat[i][j] - 1;
        return mat;
    }
};

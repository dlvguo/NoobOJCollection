#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool cmp(const vector<int> &v1, const vector<int> &v2)
    {
        if (v1[0] == v2[0])
            return v1[1] < v2[1];
        return v1[0] < v2[0];
    }

    vector<vector<int>> bicycleYard(vector<int> &position, vector<vector<int>> &terrain, vector<vector<int>> &obstacle)
    {
        vector<vector<unordered_set<int>>> used(terrain.size(), vector<unordered_set<int>>(terrain[0].size()));
        //初始化的插入
        used[position[0]][position[1]].insert(1);
        vector<vector<int>> res;
        queue<vector<int>> q;
        int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
        q.push({position[0], position[1], 1});
        while (q.size())
        {
            int size = q.size();
            while (size--)
            {
                vector<int> v = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int _x = dir[i][0] + v[0], _y = dir[i][1] + v[1];
                    if (_x < 0 || _x >= terrain.size() || _y < 0 || _y >= terrain[0].size())
                        continue;
                    int speed = v[2] + (terrain[v[0]][v[1]] - terrain[_x][_y] - obstacle[_x][_y]);
                    if (used[_x][_y].find(speed) != used[_x][_y].end() || speed <= 0)
                        continue;
                    if (speed == 1)
                        res.push_back({_x, _y});
                    used[_x][_y].insert(speed);
                    q.push({_x, _y, speed});
                }
            }
        }
        sort(res.begin(), res.end(), cmp);
        return res;
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    struct record
    {
        int step = 0;
        unordered_set<int> uset;
    };

    vector<vector<int>> res;
    vector<record> recs;
    //  行 列
    int m, n;
    int dir[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};
    static int cmp(const vector<int> v1, const vector<int> v2)
    {
        if (v1[0] == v2[0])
            return v1[1] < v2[1];
        return v1[0] < v2[0];
    }
    void dfs(int x, int y, int speed, vector<vector<int>> &terrain, vector<vector<int>> &obstacle)
    {
        for (int i = 0; i < 8; i++)
        {
            int _x = x + dir[i][0], _y = y + dir[i][1];
            if (_x < 0 || _y < 0 || _x >= m || _y >= n)
                continue;
            int _speed = speed + (terrain[x][y] - terrain[_x][_y] - obstacle[_x][_y]);
            //说明走过了
            if (_speed < 1 || recs[_x * m + _y].uset.find(_speed) != recs[_x * m + _y].uset.end() || recs[_x * m + _y].step > 10)
                continue;
            if (_speed == 1)
            {
                res.push_back({_x, _y});
            }
            recs[_x * m + _y].uset.insert(_speed);
            recs[_x * m + _y].step++;
            dfs(_x, _y, _speed, terrain, obstacle);
        }
    }

    vector<vector<int>> bicycleYard(vector<int> &position, vector<vector<int>> &terrain, vector<vector<int>> &obstacle)
    {
        m = terrain.size();
        n = terrain[0].size();
        recs.resize(m * n + 1);
        recs[position[0] * m + position[1]].step = 1;
        recs[position[0] * m + position[1]].uset.insert(1);
        dfs(position[0], position[1], 1, terrain, obstacle);
        sort(res.begin(), res.end(), cmp);
        return res;
    }
};

int cmp(const vector<int> v1, const vector<int> v2)
{
    if (v1[0] == v2[0])
        return v1[1] < v2[1];
    return v1[0] < v2[0];
}
int main()
{
    vector<int> pos = {1, 1};
    vector<vector<int>> vts;
    vector<int> v1{5, 0};
    vector<int> v2{0, 6};
    vector<int> v3{0, 6};
    vector<int> v4{7, 0};
    vector<vector<int>> vts2;

    vts.push_back(v1);
    vts.push_back(v2);
    vts2.push_back(v3);
    vts2.push_back(v4);
    Solution s;
    s.bicycleYard(pos, vts, vts2);
    cout << 'fi' << endl;
}
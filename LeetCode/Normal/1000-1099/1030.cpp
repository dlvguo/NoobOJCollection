#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
    {
        vector<vector<int>> ret;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                ret.push_back({i, j});
            }
        }
        sort(ret.begin(), ret.end(), [=](vector<int> &a, vector<int> &b) {
            return abs(a[0] - r0) + abs(a[1] - c0) < abs(b[0] - r0) + abs(b[1] - c0);
        });
        return ret;
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int ans = 0;
        unordered_map<int, int> umap;
        for (int i = 0; i < points.size(); i++)
        {
            umap.clear();
            for (int j = 0; j < points.size(); j++)
            {
                if (i != j)
                {
                    int dis = (points[j][0] - points[i][0]) * (points[j][0] - points[i][0]) + (points[j][1] - points[i][1]) * (points[j][1] - points[i][1]);
                    umap[dis]++;
                }
            }
            for (auto pair : umap)
            {
                if (pair.second > 1)
                {
                    ans += (pair.second) * (pair.second - 1);
                }
            }
        }
        return ans;
    }
};
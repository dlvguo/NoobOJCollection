#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) -> bool
        { return a.second < b.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);

        vector<int> boundaries;
        for (auto &building : buildings)
        {
            boundaries.emplace_back(building[0]);
            boundaries.emplace_back(building[1]);
        }
        sort(boundaries.begin(), boundaries.end());

        vector<vector<int>> ret;
        int n = buildings.size(), idx = 0;
        for (auto &boundary : boundaries)
        {
            while (idx < n && buildings[idx][0] <= boundary)
            {
                que.emplace(buildings[idx][1], buildings[idx][2]);
                idx++;
            }
            while (!que.empty() && que.top().first <= boundary)
            {
                que.pop();
            }

            int maxn = que.empty() ? 0 : que.top().second;
            if (ret.size() == 0 || maxn != ret.back()[1])
            {
                ret.push_back({boundary, maxn});
            }
        }
        return ret;
    }
};

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n);

        function<bool(int)> safe = [&](int x)
        {
            if (color[x] > 0)
            {
                return color[x] == 2;
            }
            color[x] = 1;
            for (int y : graph[x])
            {
                if (!safe(y))
                {
                    return false;
                }
            }
            color[x] = 2;
            return true;
        };

        vector<int> ans;
        for (int i = 0; i < n; ++i)
        {
            if (safe(i))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
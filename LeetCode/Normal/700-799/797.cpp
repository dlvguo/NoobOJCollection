#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int vis[16] = {0};
    vector<vector<int>> vts;
    int n;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<int> p = {0};
        n = graph.size();
        dfs(p, 0, graph);
        return vts;
    }

    void dfs(vector<int> p, int src, vector<vector<int>> &graph)
    {
        if (src == n - 1)
        {
            vts.push_back(p);
            return;
        }
        vis[src] = 1;
        for (auto tar : graph[src])
        {
            if (vis[tar])
                continue;
            p.push_back(tar);
            dfs(p, tar, graph);
            p.pop_back();
        }
        vis[src] = 0;
    }
};

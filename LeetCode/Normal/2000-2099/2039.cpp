#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience)
    {
        int n = patience.size();
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);
        for (auto &v : edges)
        {
            adj[v[0]].emplace_back(v[1]);
            adj[v[1]].emplace_back(v[0]);
        }

        queue<int> qu;
        qu.emplace(0);
        visit[0] = true;
        int dist = 1;
        int ans = 0;
        while (!qu.empty())
        {
            int sz = qu.size();
            for (int i = 0; i < sz; ++i)
            {
                int curr = qu.front();
                qu.pop();
                for (auto &v : adj[curr])
                {
                    if (visit[v])
                    {
                        continue;
                    }
                    qu.emplace(v);
                    int time = patience[v] * ((2 * dist - 1) / patience[v]) + 2 * dist + 1;
                    ans = max(ans, time);
                    visit[v] = true;
                }
            }
            dist++;
        }
        return ans;
    }
};

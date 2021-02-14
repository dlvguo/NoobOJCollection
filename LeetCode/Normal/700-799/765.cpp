#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSwapsCouples(vector<int> &row)
    {
        int n = row.size();
        int tot = n / 2;

        vector<vector<int>> graph(tot);
        for (int i = 0; i < n; i += 2)
        {
            int l = row[i] / 2;
            int r = row[i + 1] / 2;
            if (l != r)
            {
                graph[l].push_back(r);
                graph[r].push_back(l);
            }
        }
        vector<int> visited(tot, 0);
        int ret = 0;
        for (int i = 0; i < tot; i++)
        {
            if (visited[i] == 0)
            {
                queue<int> q;
                visited[i] = 1;
                q.push(i);
                int cnt = 0;

                while (!q.empty())
                {
                    int x = q.front();
                    q.pop();
                    cnt += 1;

                    for (int y : graph[x])
                    {
                        if (visited[y] == 0)
                        {
                            visited[y] = 1;
                            q.push(y);
                        }
                    }
                }
                ret += cnt - 1;
            }
        }
        return ret;
    }
};

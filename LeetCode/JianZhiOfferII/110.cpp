#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;

    int visit[16] = {0};

    int path[16] = {0};

    void dfs(int node, vector<vector<int>> &graph)
    {
        visit[node] = 1;
        if (node == graph.size() - 1)
        {
            vector<int> temp;
            temp.push_back(0);
            int i = 0;
            while (i != graph.size() - 1)
            {
                i = path[i];
                temp.push_back(i);
            }
            res.push_back(temp);
            visit[node] = 0;
            return;
        }
        for (int i = 0; i < graph[node].size(); i++)
        {
            if (visit[graph[node][i]])
                continue;
            path[node] = graph[node][i];
            dfs(graph[node][i], graph);
        }
        visit[node] = 0;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        dfs(0, graph);
        return res;
    }
};
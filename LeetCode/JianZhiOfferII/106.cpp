#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //表示未染色
    int g[105] = {0};
    bool tag = true;

    //代表需要染的颜色
    void dfs(int nowNode, int color, vector<vector<int>> &graph)
    {
        if (g[nowNode])
        {
            if (g[nowNode] != color)
            {
                tag = false;
            }
            return;
        }
        else
        {
            g[nowNode] = color;
            for (int i = 0; i < graph[nowNode].size(); i++)
            {
                int nei = graph[nowNode][i];
                dfs(nei, color == 1 ? 2 : 1, graph);
                if (!tag)
                    return;
            }
        }
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        for (int i = 0; i < graph.size(); i++)
            if (!g[i])
                dfs(i, 1, graph);
        return tag;
    }
};
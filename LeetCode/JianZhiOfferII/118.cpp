#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nodes, int x)
    {
        if (nodes[x] == x)
            return x;
        return nodes[x] = search(nodes, nodes[x]);
    }


    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> nodes(n + 1);
        for (int i = 1; i < nodes.size(); i++)
            nodes[i] = i;
        for (int i = 0; i < n; i++)
        {
            int f1 = search(nodes,edges[i][0]);
            int f2 = search(nodes,edges[i][1]);

            if (f1 == f2)
                return edges[i];
            nodes[f2] = f1;
        }
        return edges.back();
    }
};
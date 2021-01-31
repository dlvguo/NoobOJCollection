#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //寻找祖先
    int SearchAncestor(vector<int> &sets, int x)
    {
        if (sets[x] == -1)
            return x;
        return sets[x] = SearchAncestor(sets, sets[x]);
    }

    //集合
    bool Union(vector<int> &sets, int a, int b)
    {
        int fa = SearchAncestor(sets, a), fb = SearchAncestor(sets, b);
        if (fa == fb)
            return false;
        //注意并查集的树头
        sets[fa] = fb;
        return true;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        //先合并公共边3的并查集 之后再分别做1和2类型
        vector<int> sets1(n + 1, -1);
        int ans = 0;
        for (int i = 0; i < edges.size(); i++)
        {
            if (edges[i][0] == 3)
            {
                if (!Union(sets1, edges[i][1], edges[i][2]))
                    ans++;
            }
        }
        vector<int> sets2(sets1);
        for (int i = 0; i < edges.size(); i++)
        {
            if (edges[i][0] == 1)
            {
                if (!Union(sets1, edges[i][1], edges[i][2]))
                    ans++;
            }
            else if (edges[i][0] == 2)
            {
                if (!Union(sets2, edges[i][1], edges[i][2]))
                    ans++;
            }
        }
        int c1 = 0, c2 = 0;
        for (int i = 1; i < sets1.size(); i++)
        {
            if (sets1[i] == -1)
            {
                c1++;
                if (c1 > 1)
                    return -1;
            }
            if (sets2[i] == -1)
            {
                c2++;
                if (c2 > 1)
                    return -1;
            }
        }

        return ans;
    }
};
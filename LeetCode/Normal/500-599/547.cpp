#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int root[101] = {0};

    int findAncestor(int n)
    {
        if (root[n] == 0)
        {
            return n;
        }
        return root[n] = findAncestor(root[n]);
    }

    void U(int a, int b)
    {
        int aroot = findAncestor(a), broot = findAncestor(b);
        if (aroot != broot || aroot == 0)
            root[broot] = aroot;
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        for (int i = 0; i < isConnected.size(); i++)
        {
            for (int j = i + 1; j < isConnected[i].size(); j++)
            {
                if (isConnected[i][j])
                {
                    U(i + 1, j + 1);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= isConnected.size(); i++)
        {
            if (!root[i])
                ans++;
        }
        return ans;
    }
};
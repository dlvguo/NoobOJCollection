#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int uset[255] = {0};
    int search(int x)
    {
        if (uset[x] == x)
            return x;
        return uset[x] = search(uset[x]);
    }

    void unionset(int a, int b)
    {
        int af = search(a), bf = search(b);
        if (af != bf)
            uset[bf] = af;
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        for (int i = 0; i < isConnected.size(); i++)
            uset[i] = i;
        for (int i = 0; i < isConnected.size(); i++)
            for (int j = i + 1; j < isConnected[0].size(); j++)
            {
                if (isConnected[i][j])
                    unionset(i, j);
            }
        int res = 0;
        for (int i = 0; i < isConnected.size(); i++)
            if (uset[i] == i)
                res++;
        return res;
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> res;

    vector<int> lexicalOrder(int n)
    {
        dfs(1, n);
        return res;
    }

    void dfs(int cur, int limit)
    {
        if (cur > limit)
            return;
        res.push_back(cur);
        for (int i = 0; i < 9; i++)
            dfs(cur * 10 + i, limit);
    }
};
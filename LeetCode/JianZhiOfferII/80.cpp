#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> temp;
    int tn, tk;
    vector<vector<int>> combine(int n, int k)
    {
        tn = n;
        tk = k;
        dfs(1);
        return res;
    }
    void dfs(int index)
    {
        if ((tn - index) + temp.size() + 1 < tk || index > tn)
            return;
        temp.push_back(index);
        if (temp.size() == tk)
        {
            res.push_back(temp);
        }
        else
        {
            dfs(index + 1);
        }
        temp.pop_back();
        dfs(index + 1);
    }
};
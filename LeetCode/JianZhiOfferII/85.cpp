#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string temp;
    vector<string> res;
    int _n;
    void dfs(int l, int r)
    {
        if (l > _n)
            return;
        if (r == _n)
        {
            res.push_back(temp);
            return;
        }
        temp.push_back('(');
        dfs(l + 1, r);
        temp.pop_back();
        if (l > r)
        {
            temp.push_back(')');
            dfs(l, r + 1);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        _n = n;
        dfs(0, 0);
        return res;
    }
};
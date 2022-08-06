#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> res;
    string temp = "";

    void dfs(int l, int r, int n)
    {
        if (r > l || l > n)
            return;
        if (r == n)
        {
            res.push_back(temp);
            return;
        }

        temp.push_back('(');
        dfs(l + 1, r, n);
        temp.pop_back();

        temp.push_back(')');
        dfs(l, r + 1, n);
        temp.pop_back();
    }

    vector<string> generateParenthesis(int n)
    {
        dfs(0, 0, n);
        return res;
    }
};
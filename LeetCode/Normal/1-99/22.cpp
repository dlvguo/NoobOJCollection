#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
#include <vector>
using namespace std;

void dfs(vector<string> &ans, string &res, int l, int r, int n)
{
    if (r > l || l > n || r > n)
        return;
    if (l == r && r == n)
    {
        ans.push_back(res);
    }
    res.push_back('(');
    dfs(ans, res, l + 1, r, n);
    res.pop_back();
    res.push_back(')');
    dfs(ans, res, l, r + 1, n);
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    if (!n)
        return ans;
    string str;
    dfs(ans, str, 0, 0, n);
    return ans;
}

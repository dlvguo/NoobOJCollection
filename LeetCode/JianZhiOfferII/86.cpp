#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> res;
    vector<string> temp;

    bool check(string &s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

    void dfs(string &s, int index)
    {
        if (index >= s.size())
        {
            res.push_back(temp);
            return;
        }
        string _s;
        for (int i = index; i < s.size(); i++)
        {
            _s.push_back(s[i]);
            if (check(_s))
            {
                temp.push_back(_s);
                dfs(s, i + 1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        dfs(s,0);
        return res;
    }
};
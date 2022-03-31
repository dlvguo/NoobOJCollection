#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> res, temp;

    void dfs(string &s, int index)
    {
        if (index >= s.size())
        {
            if (temp.size() == 4)
            {
                string t = temp[0] + "." + temp[1] + "." + temp[2] + "." + temp[3];
                res.push_back(t);
            }
            return;
        }
        if (!(temp.size() < 4 && (3 - temp.size()) * 3 < s.size() - index - 1))
        {
            string _s = {s[index]};

            temp.push_back(_s);
            dfs(s, index + 1);
            temp.pop_back();
        }
        if (s[index] != '0')
        {
            if (index < s.size() - 1)
            {
                if (!(temp.size() < 4 && (3 - temp.size()) * 3 < s.size() - index - 2))
                {
                    string _s = {s[index], s[index + 1]};
                    temp.push_back(_s);
                    dfs(s, index + 2);
                    temp.pop_back();
                }
            }
            if (index < s.size() - 2)
            {

                if (!(temp.size() < 4 && (3 - temp.size()) * 3 < s.size() - index - 3))
                {
                    string _s = {s[index], s[index + 1], s[index + 2]};
                    if (_s < "256")
                    {
                        temp.push_back(_s);
                        dfs(s, index + 3);
                        temp.pop_back();
                    }
                }
            }
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        if (s.size() < 4 || s.size() > 12)
            return {};
        dfs(s, 0);
        return res;
    }
};
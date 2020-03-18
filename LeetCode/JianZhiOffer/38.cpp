#include <bits/stdc++.h>
#include <set>
using namespace std;

class Solution
{
public:
    bool visit[9] = {false};
    set<string> strSet;
    void dfs(string s, int num, string str)
    {
        if (num == s.size())
        {
            strSet.insert(str);
        }
        else
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (visit[i] == 0)
                {
                    visit[i] = 1;
                    str.push_back(s[i]);
                    dfs(s, num + 1, str);
                    str.pop_back();
                    visit[i] = 0;
                }
            }
        }
    }

    vector<string> permutation(string s)
    {
        string str;
        dfs(s, 0, str);
        vector<string> strs(strSet.begin(), strSet.end());
        return strs;
    }
};
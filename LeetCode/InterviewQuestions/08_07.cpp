#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int visit[27] = {0};

    string temp = "";
    vector<string> res;
    void dfs(string &S)
    {
        if (temp.size() == S.size())
        {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < S.size(); i++)
            if (!visit[i])
            {
                visit[i] = 1;
                temp.push_back(S[i]);
                dfs(S);
                temp.pop_back();
                visit[i] = 0;
            }
    }

    vector<string> permutation(string S)
    {
        dfs(S);
        return res;
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> decodeStr(string &s)
    {
        vector<int> res;
        string temp = "";
        int index = 0;
        while (s[index] != ':')
        {
            temp.push_back(s[index++]);
            /* code */
        }
        res.push_back(atoi(temp.c_str()));
        index++;
        temp = "";
        while (s[index] != ':')
        {
            temp.push_back(s[index++]);
            /* code */
        }
        if (temp[0] == 's')
            res.push_back(0);
        else
            res.push_back(1);

        index++;
        temp = "";
        while (index < s.size())
        {
            temp.push_back(s[index++]);
        }
        res.push_back(atoi(temp.c_str()));
        return res;
    }

    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        vector<int> ans(n, 0);
        stack<pair<int, int>> stk;
        int temp = 0;
        for (auto log : logs)
        {
            vector<int> res = decodeStr(log);
            if (res[1])
            {
                auto p = stk.top();
                stk.pop();
                ans[res[0]] += (res[2] - p.second + 1);
                if (stk.size())
                {
                    auto t = stk.top();
                    stk.pop();
                    // 更新新的start
                    stk.push(make_pair(t.first, res[2] + 1));
                }
            }
            else
            {
                if (stk.size())
                {
                    auto p = stk.top();
                    ans[p.first] += (res[2] - p.second);
                }
                stk.push(make_pair(res[0], res[2]));
            }
        }
        return ans;
    }
};
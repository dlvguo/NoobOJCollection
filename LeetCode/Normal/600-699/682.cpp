#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        vector<int> res;
        for (auto op : ops)
        {
            if (op == "D")
            {
                res.push_back(res[res.size() - 1] * 2);
            }
            else if (op == "C")
                res.pop_back();
            else if (op == "+")
                res.push_back(res[res.size() - 1] + res[res.size() - 2]);
            else
                res.push_back(atoi(op.c_str()));
        }
        int ans = 0;
        for (auto r : res)
        {
            ans += r;
        }
        return ans;
    }
};
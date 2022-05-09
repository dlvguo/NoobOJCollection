#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        int l = 0, r = s.size();
        vector<int> res;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'I')
                res.push_back(l++);
            else
                res.push_back(r--);
        }
        res.push_back(l);
        return res;
    }
};
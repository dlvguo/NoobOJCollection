#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {

        unordered_map<string, int> _s1, _s2;

        vector<string> res;
        string str = "";
        for (auto ch : s1)
        {
            if (ch == ' ' && str.size() > 0)
            {
                _s1[str]++;
                str = "";
            }
            else
            {
                str.push_back(ch);
            }
        }
        if (str.size() > 0)
            _s1[str]++;
        str = "";
        for (auto ch : s2)
        {
            if (ch == ' ' && str.size() > 0)
            {
                _s2[str]++;
                str = "";
            }
            else
            {
                str.push_back(ch);
            }
        }
        if (str.size() > 0)
        {
            _s2[str]++;
        }

        for (auto k1 : _s1)
        {
            if (_s1[k1.first] == 1)
                if (!_s2[k1.first])
                    res.push_back(k1.first);
        }
        for (auto k2 : _s2)
        {
            if (_s2[k2.first] == 1)
                if (!_s1[k2.first])
                    res.push_back(k2.first);
        }
        return res;
    }
};
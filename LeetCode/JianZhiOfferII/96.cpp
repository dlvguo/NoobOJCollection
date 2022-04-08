#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string _s1, _s2, _s3;
    unordered_set<string> _set;
    bool dfs(int s1index, int s2index, int s3index)
    {
        if (s3index == _s3.size())
            return true;
        string s = to_string(s1index) + "-" + to_string(s2index) + "-" + to_string(s3index);
        if (_set.find(s) != _set.end())
            return false;
        _set.insert(s);
        if (s1index == _s1.size())
        {
            if (_s2[s2index] == _s3[s3index])
            {
                return dfs(s1index, s2index + 1, s3index + 1);
            }
            return false;
        }
        if (s2index == _s2.size())
        {
            if (_s1[s1index] == _s3[s3index])
            {
                return dfs(s1index + 1, s2index, s3index + 1);
            }
            return false;
        }

        if (_s1[s1index] == _s3[s3index] && _s2[s2index] == _s3[s3index])
        {
            return dfs(s1index + 1, s2index, s3index + 1) || dfs(s1index, s2index + 1, s3index + 1);
        }
        if (_s1[s1index] == _s3[s3index])
        {
            return dfs(s1index + 1, s2index, s3index + 1);
        }
        if (_s2[s2index] == _s3[s3index])
        {
            return dfs(s1index, s2index + 1, s3index + 1);
        }
        return false;
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length() + s2.length() != s3.size())
            return false;
        if (!s3.size())
            return true;
        _s1 = s1;
        _s2 = s2;
        _s3 = s3;
        return dfs(0, 0, 0);
    }
};
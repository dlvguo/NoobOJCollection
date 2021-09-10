#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int j = 0;
        vector<int> next(s.size(), 0);
        for (int i = 1; i < s.size(); i++)
        {
            while (j > 0 && s[j] != s[i])
            {
                j = next[j - 1];
            }
            if (s[j] == s[i])
                next[i] = ++j;
        }
        //注意求0
        return next.back() != 0 && s.size() % (s.size() - next.back()) == 0;
    }
};
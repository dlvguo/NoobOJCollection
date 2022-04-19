#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        vector<int> res(s.size(), 0);
        vector<int> cindex;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == c)
                cindex.push_back(i);
        }

        for (int i = 0; i < cindex[0]; i++)
        {
            res[i] = abs(cindex[0] - i);
        }

        for (int i = 0; i < cindex.size() - 1; i++)
        {
            int l = cindex[i], r = cindex[i + 1];
            for (int j = l + 1; j < r; j++)
                res[j] = min(abs(j - l), abs(j - r));
        }

        for (int i = cindex.back() + 1; i < s.size(); i++)
        {
            res[i] = abs(cindex.back() - i);
        }
        return res;
    }
};
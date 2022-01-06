#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string modifyString(string s)
    {
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '?')
            {
                for (char ch = 'a'; ch <= 'c'; ++ch)
                {
                    if ((i > 0 && s[i - 1] == ch) || (i < n - 1 && s[i + 1] == ch))
                    {
                        continue;
                    }
                    s[i] = ch;
                    break;
                }
            }
        }
        return s;
    }
};
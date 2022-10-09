#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        if (s.size() == 2)
        {
            return 1;
        }
        int bal = 0, n = s.size(), len;
        for (int i = 0; i < n; i++)
        {
            bal += (s[i] == '(' ? 1 : -1);
            if (bal == 0)
            {
                len = i + 1;
                break;
            }
        }
        if (len == n)
        {
            return 2 * scoreOfParentheses(s.substr(1, n - 2));
        }
        else
        {
            return scoreOfParentheses(s.substr(0, len)) + scoreOfParentheses(s.substr(len, n - len));
        }
    }
};

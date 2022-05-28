#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string res;
        string sk;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ')')
            {
                if (sk.size() != 1)
                    res.push_back(')');

                sk.pop_back();
            }
            else
            {
                if (sk.size())
                    res.push_back('(');
                sk.push_back('(');
            }
        }
        return res;
    }
};
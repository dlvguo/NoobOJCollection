#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> v;
        int index = 0;
        while (index < s.size() && s[index] == ' ')
        {
            index++;
        }
        string str;
        for (; index < s.size(); index++)
        {
            if (s[index] != ' ')
            {
                str.push_back(s[index]);
            }
            else
            {
                if (str.size())
                {
                    v.push_back(str);
                    str.clear();
                }
            }
        }
        if (str.size())
        {
            v.push_back(str);
            str.clear();
        }
        if (v.size())
        {
            for (int i = v.size() - 1; i >= 0; i--)
            {

                str += v[i];
                str += ' ';
            }
            str.pop_back();
        }
        return str;
    }
};
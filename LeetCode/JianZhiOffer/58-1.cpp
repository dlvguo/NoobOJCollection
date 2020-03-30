#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string str;
        int index = s.length() - 1;
        while (index >= 0 && s[index] == ' ')
        {
            index--;
        }
        string tempStr;
        while (index >= 0)
        {
            if (s[index] == ' ')
            {
                reverse(tempStr.begin(), tempStr.end());
                s.push_back(tempStr);
                s.push_back(' ');
                tempStr.clear();
                while (index >= 0 && s[index] == ' ')
                {
                    index--;
                }
                continue;
            }
            else
            {
                tempStr.push_back(s[index--]);
            }
        }
        if (tempStr.size() != 0)
            str.push_back(tempStr);
        else
        {
            str.pop_back();
        }
        return str;
    }
};
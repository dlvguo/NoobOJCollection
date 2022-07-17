#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> bulidNext(string s)
    {
        vector<int> next(s.size(), 0);

        int j = 0;
        for (int i = 1; i < s.size(); i++)
        {
            while (j > 0 && s[j] != s[i])
            {
                j = next[j - 1];
            }
            if (s[i] == s[j])
                next[i] = ++j;
        }
        return next;
    }

    bool isFlipedString(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;
        if (s1.size() == 0 && s2.size() == 0)
            return true;
        s1 += s1;
        vector<int> next = bulidNext(s2);

        int s1Index = 0, s2Index = 0;
        while (s1Index < s1.size())
        {
            if (s2[s2Index] == s1[s1Index])
            {
                s1Index++;
                s2Index++;
                if (s2Index == s2.size())
                    return true;
            }
            else
            {
                if (s2Index > 0)
                {
                    s2Index = next[s2Index - 1];
                }
                else
                {
                    s1Index++;
                }
            }
        }
        return false;
    }
};
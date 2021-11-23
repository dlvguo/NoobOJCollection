#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;
        int jdnum = 0, ch1, ch2;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != goal[i])
            {
                jdnum++;
                if (jdnum == 1)
                {
                    ch1 = s[i];
                    ch2 = goal[i];
                }
                else if (jdnum == 2)
                {
                    if (ch1 != goal[i] || ch2 != s[i])
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            /* code */
        }
        if (jdnum == 0)
        {
            int hash[26] = {0};
            for (int i = 0; i < s.size(); i++)
            {
                hash[s[i] - 'a']++;
                if (hash[s[i] - 'a'] == 2)
                    return true;
            }
        }
        return jdnum == 2;
    }
};
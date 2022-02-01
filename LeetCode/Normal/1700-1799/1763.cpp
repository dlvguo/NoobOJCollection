#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int sc[26] = {0}, bc[26] = {0};

    bool check()
    {
        for (int i = 0; i < 26; i++)
        {
            if (sc[i] && bc[i])
                continue;
            if (sc[i] || bc[i])
                return false;
        }
        return true;
    }

    string longestNiceSubstring(string s)
    {
        string res = "";
        string temp = "";
        for (int i = 0; i < s.size(); i++)
        {

            temp = "";
            for (int j = i; j < s.size(); j++)
            {
                /* code */
                temp.push_back(s[j]);
                if (s[j] >= 'a')
                    sc[s[j] - 'a']++;
                else
                    bc[s[j] - 'A']++;
                if (check() && temp.size() > res.size())
                    res = temp;
            }
            memset(sc, 0, sizeof(sc));
            memset(bc, 0, sizeof(bc));
        }
        return res;
    }
};
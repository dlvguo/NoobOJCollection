#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int firstUniqChar(string s)
    {
        int index[26] = {0}, ch[26] = {0};
        int res = -1;
        for (int i = 0; i < s.size(); i++)
        {
            int t = s[i] - 'a';
            ch[t]++;
            index[t] = i;
        }
        for (int i = 0; i < 26; i++)
        {
            if (ch[i] == 1)
            {
                if (res == -1)
                    res = index[i];
                else
                {
                    res = min(res, index[i]);
                }
            }
        }
        return res;
    }
};
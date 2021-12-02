#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxPower(string s)
    {
        int res = 0, temp = 0;
        for (int i = 0; i < s.size();)
        {
            temp = 1;
            int j = i + 1;
            while (j < s.size() && s[j] == s[i])
            {
                temp++;
                j++;
            }
            i = j;
            res = max(res, temp);
        }
        return res;
    }
};

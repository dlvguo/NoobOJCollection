#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int r = strs.size(), l = strs[0].size();
        int res = 0;
        for (int i = 0; i < l; i++)
        {
            char pre = strs[0][i];
            for (int j = 1; j < r; j++)
            {
                char n = strs[j][i];
                if (pre > n)
                {
                    res++;
                    break;
                }
                else
                    pre = n;
            }
        }
        return res;
    }
};
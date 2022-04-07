#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        // znum 表示需要变成全0的时候需要的数量 onenum表示维持递增需要的最小数量
        int znum = 0, onenum = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                znum++;
            }
            else
            {
                onenum = min(znum, onenum + 1);
            }
        }
        return min(onenum, znum);
    }
};
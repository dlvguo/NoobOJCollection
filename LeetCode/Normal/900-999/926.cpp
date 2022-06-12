#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {

        int low = 0, up = 0;
        for (int i = 0; i < s.size(); i++)
        {
            // low 不变 维持up的话要+1
            if (s[i] == '0')
            {
                up = min(up + 1, low);
            }
            // 等于1的话
            else
            {
                low = low + 1;
            }
        }
        return min(low, up);
    }
};
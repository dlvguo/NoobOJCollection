#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        vector<int> dp(days.back() + 1, 0);
        for (int i = 0; i < days.size(); i++)
        {
            dp[days[i]] = -1; //标记当天去旅行
        }
        int a, b, c;
        for (int i = 1; i <= days.back(); i++)
        {
            if (dp[i] == 0) //当天不旅行
                dp[i] = dp[i - 1];
            else //当天旅行
            {
                a = dp[i - 1] + costs[0];
                if (i - 7 >= 0) //要考虑 i-7 为负数的情况！！！
                    b = dp[i - 7] + costs[1];
                else
                    b = costs[1];
                if (i - 30 >= 0)
                    c = dp[i - 30] + costs[2];
                else
                    c = costs[2];
                dp[i] = min(a, b); //求a,b,c的最小值
                dp[i] = min(c, dp[i]);
            }
        }
        return dp[days.back()];
    }
};
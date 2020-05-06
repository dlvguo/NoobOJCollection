#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int num = days.back();
        vector<int> dp(num + 1, 0);
        for (int i = 0; i < days.size(); i++)
        {
            dp[days[i]] = 1; //标记当天去旅行
        }
        int one, seven, thirty;

        for (int i = 1; i <= 6 && i <= num; i++)
        {
            if (!dp[i])
                dp[i] = dp[i - 1];
            else
            {
                one = dp[i - 1] + costs[0];
                seven = costs[1];
                thirty = costs[2];
                dp[i] = min(one, min(seven, thirty));
            }
        }
        for (int i = 7; i <= 29 && i <= num; i++)
        {
            if (!dp[i])
                dp[i] = dp[i - 1];
            else
            {
                one = dp[i - 1] + costs[0];
                seven = dp[i - 7] + costs[1];
                thirty = costs[2];
                dp[i] = min(one, min(seven, thirty));
            }
        }
        for (int i = 30; i <= num; i++)
        {
            if (!dp[i])
                dp[i] = dp[i - 1];
            else
            {
                one = dp[i - 1] + costs[0];
                seven = dp[i - 7] + costs[1];
                thirty = dp[i - 30] + costs[2];
                dp[i] = min(one, min(seven, thirty));
            }
        }
        return dp[num];
    }
};
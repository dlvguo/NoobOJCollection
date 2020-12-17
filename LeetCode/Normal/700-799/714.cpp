#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        //  持有               非持有
        int hold = -prices[0], nothold = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            // 当前非持有只跟前面比 要么继续不持有 要么就从前面的持有抛弃
            int t = max(nothold, hold - fee + prices[i]);
            // 当前持有只跟前面比 要么继续持有 要么就从前面的非持有入手
            hold = max(hold, nothold - prices[i]);
            nothold = t;
        }
        return nothold;
    }
};
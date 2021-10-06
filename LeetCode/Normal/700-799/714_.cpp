#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int minprice = prices[0];
        int res = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < minprice)
            {
                minprice = prices[i];
            }
            //有利润
            else if (prices[i] - fee > minprice)
            {
                res += prices[i] - fee - minprice;
                minprice = prices[i] - fee;
            }
        }
        return res;
    }
};
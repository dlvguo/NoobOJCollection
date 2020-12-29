#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        //max_profits[i]为第i次最大利益,第0次为0
        //思路其实就是把后面的成本和前面的最大利益做减法,作为后面的成本
        vector<int> min_prices(k, 0x7fffffff), max_profits(k + 1, 0);
        for (int &price : prices)
        {
            for (int i = 0; i < k; ++i)
            {
                min_prices[i] = min(min_prices[i], price - max_profits[i]);
                max_profits[i + 1] = max(max_profits[i + 1], price - min_prices[i]);
            }
        }
        return max_profits[k];
    }
};
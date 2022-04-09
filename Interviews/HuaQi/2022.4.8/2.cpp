#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 请写一个方法，得出在这段时间内，如果有一次买和卖的机会（当然买在前，卖在后），可能获得的最大收益是多少。
     * @param prices int整型vector 长度范围1-200000，每个数的范围0-2000000000
     * @return int整型
     */
    int maxProfit(vector<int> &prices)
    {
        int res=0;
        int _min=INT32_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            if(_min>prices[i])
                _min=prices[i];
            else
                res=max(prices[i]-_min,res);
        }
        return res;
        // write code here
    }
};
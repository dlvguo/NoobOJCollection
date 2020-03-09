#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 1)
            return 0;
        int minest = -1, maxest, mIndex = 0, max = 0;
        while (mIndex < prices.size())
        {
            maxest = prices[mIndex];
            if (minest == -1 || minest > maxest)
                minest = maxest;
            mIndex++;
            while (mIndex < prices.size() && maxest < prices[mIndex])
            {
                maxest = prices[mIndex];
                mIndex++;
            }
            if (maxest - minest > max)
                max = maxest - minest;
        }
        return max;
    }
};

int mian(){
    Solution s1;
    vector<int> v={7,6,4,3,1};
    cout<<s1.maxProfit(v);
}
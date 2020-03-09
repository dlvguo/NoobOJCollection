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

//动态规划法
int maxProfit(vector<int> &prices)
{
    if (prices.size() <= 1)
        return 0;
    int n = prices[0];
    int max = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > n)
        {
            max = max > prices[i] - n ? max : prices[i] - n;
        }
        else
        {
            max = prices[i];
        }
    }

    return max;
}

int main()
{
    Solution s1;
    vector<int> v = {7, 6, 4, 3, 1};
    cout << s1.maxProfit(v);
    system("pause");
    return 0;
}
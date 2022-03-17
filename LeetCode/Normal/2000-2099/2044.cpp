#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int res = 1;
        int value = nums[0];
        int mask = 1 << nums.size();
        vector<int> dp(mask);
        unordered_map<int, int> ids;
        for (int i = 0; i < nums.size(); i++)
        {
            ids[1 << i] = nums[i];
        }

        for (int i = 2; i < mask; i++)
        {
            int lowbit = i & (-i);
            dp[i] = dp[i - lowbit] | ids[lowbit];
            if (dp[i] == value)
                res++;
            else if (dp[i] > value)
            {
                res = 1;
                value = dp[i];
            }
        }
        return res;
    }
};

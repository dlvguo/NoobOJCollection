#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        int dp[101] = {0};
        int dp2[101] = {0};

        for (int i = 0; i < nums.size(); i++)
        {
            dp[nums[i]]++;
        }
        for (int i = 1; i < 101; i++)
        {
            dp2[i] = dp[i - 1] + dp2[i - 1];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = dp2[nums[i]];
        }
        return nums;
    }
};
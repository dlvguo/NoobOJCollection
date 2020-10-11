#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans += nums[i];
        }
        if (ans & 1)
            return false;
        ans /= 2;
        int dp[10001] = {0};
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = ans; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[ans] == ans;
    }
};

int main()
{
    vector<int> nums = {1, 2, 5};
    Solution s;
    s.canPartition(nums);
}
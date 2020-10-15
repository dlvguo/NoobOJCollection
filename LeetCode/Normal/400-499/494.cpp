#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans += nums[i];
        }
        if ((ans + S) % 2 || ans < abs(S))
            return 0;
        int target = (ans + S) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= nums.size(); i++)
        {
            for (int j = target; j >= nums[i - 1]; j--)
            {
                dp[j] = dp[j] + dp[j - nums[i - 1]];
            }
        }
        return dp[target];
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << s.findTargetSumWays(nums, -3) << endl;
    system("pause");
}
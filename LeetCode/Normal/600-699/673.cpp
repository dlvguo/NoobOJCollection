#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int maxlen = 1, res = 1;
        //dp表示以nums[i]结尾的最长序列 cnt[i]表示以nums[i]结尾的长度数量
        vector<int> dp(nums.size(), 1), cnt(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if (dp[j] + 1 == dp[i])
                    {
                        cnt[i] += cnt[j];
                    }
                }
            }
            if (maxlen < dp[i])
            {
                res = cnt[i];
                maxlen = dp[i];
            }
            else if (maxlen == dp[i])
            {
                res += cnt[i];
            }
        }
        return res;
    }
};

int main()
{
    vector<int> v = {2, 2, 2, 2, 2};
    Solution s;
    cout << s.findNumberOfLIS(v);
}
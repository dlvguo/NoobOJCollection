#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum < x)
        {
            return -1;
        }

        int right = 0;
        int lsum = 0, rsum = sum;
        int ans = n + 1;

        for (int left = -1; left < n; ++left)
        {
            if (left != -1)
            {
                lsum += nums[left];
            }
            while (right < n && lsum + rsum > x)
            {
                rsum -= nums[right];
                ++right;
            }
            if (lsum + rsum == x)
            {
                ans = min(ans, (left + 1) + (n - right));
            }
        }

        return ans > n ? -1 : ans;
    }
};

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        if (k == 1)
            return 0;
        sort(nums.begin(), nums.end());
        int res = INT32_MAX;
        for (int i = 0; i <= nums.size() - k; i++)
        {
            res = min(nums[i + k - 1] - nums[i], res);
        }
        return res;
    }
};
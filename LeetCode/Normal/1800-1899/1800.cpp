#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int res = 0;
        int l = 0;
        while (l < nums.size())
        {
            int cursum = nums[l++];
            while (l < nums.size() && nums[l] > nums[l - 1])
            {
                cursum += nums[l++];
            }
            res = max(res, cursum);
        }
        return res;
    }
};

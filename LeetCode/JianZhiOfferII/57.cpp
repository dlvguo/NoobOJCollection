#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        int n = nums.size();
        set<int> rec;
        for (int i = 0; i < n; i++)
        {
            auto iter = rec.lower_bound(max(nums[i], INT_MIN + t) - t);
            if (iter != rec.end() && *iter <= min(nums[i], INT_MAX - t) + t)
            {
                return true;
            }
            rec.insert(nums[i]);
            if (i >= k)
            {
                rec.erase(nums[i - k]);
            }
        }
        return false;
    }
};
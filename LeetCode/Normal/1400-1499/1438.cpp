#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        multiset<int> s;
        int n = nums.size();
        int left = 0, right = 0;
        int ret = 0;
        while (right < n)
        {
            s.insert(nums[right]);
            while (*s.rbegin() - *s.begin() > limit)
            {
                s.erase(s.find(nums[left++]));
            }
            ret = max(ret, right - left + 1);
            right++;
        }
        return ret;
    }
};

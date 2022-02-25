#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;
        sort(nums.begin(), nums.end());
        // 肯定只能有负数 才能有这个情况
        for (int i = 0; i < nums.size() - 2 && nums[i] <= 0; i++)
        {
            // 避免重复
            if (i && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = nums.size() - 1;
            int target = -nums[i];
            while (left < right)
            {
                if (nums[left] + nums[right] == target)
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    left++;
                    right--;
                }
                else if (nums[left] + nums[right] < target)
                {
                    left++;
                }
                else
                    right--;
            }
        }
        return res;
    }
};
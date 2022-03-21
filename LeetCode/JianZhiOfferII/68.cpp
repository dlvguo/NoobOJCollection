#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, res = 0;
        if(target>nums.back())
            return nums.size();
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (nums[mid] >= target)
            {
                res = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return res;
    }
};
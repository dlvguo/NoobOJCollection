#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (mid == 0)
            {
                if (nums[mid] > nums[1])
                    return 0;
                else
                    l = mid + 1;
            }
            else if (mid == nums.size() - 1)
            {
                if (nums[mid] > nums[mid - 1])
                    return mid;
                else
                    r = mid - 1;
            }
            else
            {
                if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                    return mid;
                else if (nums[mid] > nums[mid - 1])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        return 0;
    }
};

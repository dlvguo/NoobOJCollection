#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1, mid;
        while (low < high)
        {
            mid = (low + high) / 2;
            if (mid == nums[mid])
                low = mid + 1;
            else
            {
                high = mid;
            }
        }
        return low == nums.size() - 1 && nums[low] == low ? low + 1 : low;
    }
};
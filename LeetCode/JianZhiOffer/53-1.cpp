#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int sum = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid - 1;
                while (low >= 0 && nums[low] == target)
                {
                    sum++;
                    low--;
                }
                while (mid < nums.size() && target == nums[mid])
                {
                    mid++;
                    sum++;
                }
                return sum;
            }
        }
        return sum;
    }
};
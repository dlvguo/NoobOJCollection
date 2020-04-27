#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int len = nums.size();
        int left = 0, right = len - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            //说明右边有序
            else if (nums[mid] < nums[right])
            {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            //说明左边有序
            else
            {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return -1;
    }
};
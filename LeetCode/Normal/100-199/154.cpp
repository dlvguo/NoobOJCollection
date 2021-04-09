#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high)
        {
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high])
            {
                high = pivot;
            }
            else if (nums[pivot] > nums[high])
            {
                low = pivot + 1;
            }
            else
            {
                high -= 1;
            }
        }
        return nums[low];
    }
};

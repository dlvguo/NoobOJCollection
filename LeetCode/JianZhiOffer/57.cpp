#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    int sum;
    while (left <= right)
    {
        sum = nums[left] + nums[right];
        if (sum == target)
        {
            return {nums[left], nums[right]};
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return {};
}
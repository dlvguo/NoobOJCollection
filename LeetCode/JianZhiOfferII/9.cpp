#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int left = 0, right = 0, temp = 1, res = 0;

        while (right < nums.size())
        {
            temp *= nums[right++];
            while (temp >= k && left <= right)
            {
                temp /= nums[left++];
            }
            res += left > right ? 0 : right - left + 1;
        }
        return res;
    }
};
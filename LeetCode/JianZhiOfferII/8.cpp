#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0, right = 0, temp = 0, _min = nums.size();

        while (right < nums.size())
        {
            temp += nums[right++];
            while (temp >= target&&left<=right)
            {
                _min = min(right - left, _min);
                temp -= nums[left];
                left++;
            }
        }
        return _min == nums.size() ? 0 : _min;
    }
};
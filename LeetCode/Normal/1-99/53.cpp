#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = nums[0], _max = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (sum > 0)
            {
                sum += nums[i];
            }
            else
            {
                sum = nums[i];
            }
            _max = max(sum, _max);
        }
        return _max;
    }
};
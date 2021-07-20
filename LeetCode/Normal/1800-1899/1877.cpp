#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int _max = 0;
        for (int i = 0; i < nums.size() / 2; i++)
        {
            _max = max(_max, nums[i] + nums[nums.size() - i - 1]);
        }
        return _max;
    }
};
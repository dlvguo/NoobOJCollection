#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] += nums[i - 1];
        }
        int pre = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums.back() - nums[i] == pre)
                return i;
            pre = nums[i];
        }
        return -1;
    }
};
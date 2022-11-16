#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isIdealPermutation(vector<int> &nums)
    {
        int n = nums.size(), minSuff = nums[n - 1];
        for (int i = n - 3; i >= 0; i--)
        {
            if (nums[i] > minSuff)
            {
                return false;
            }
            minSuff = min(minSuff, nums[i + 1]);
        }
        return true;
    }
};

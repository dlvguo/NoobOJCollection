#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        for (int i = 1; i <= n; ++i)
        {
            if (nums[i - 1] >= i && (i == n || nums[i] < i))
            {
                return i;
            }
        }
        return -1;
    }
};

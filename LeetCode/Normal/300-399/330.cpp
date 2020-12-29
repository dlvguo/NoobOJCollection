#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        int patches = 0;
        long long x = 1;
        int length = nums.size(), index = 0;
        while (x <= n)
        {
            if (index < length && nums[index] <= x)
            {
                x += nums[index];
                index++;
            }
            else
            {
                x <<= 1;
                patches++;
            }
        }
        return patches;
    }
};
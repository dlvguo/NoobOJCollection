#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int res = 0, temp = 1, left = 0, right = 0;
        while (right < nums.size())
        {
            temp *= nums[right++];
            while (left <= right && temp >= k)
            {
                temp/=nums[left++];
            }
            if(left<=right)
                res+=(right-left+1);
        }
        return res;
    }
};
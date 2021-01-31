#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //天平即左边重量等于右边重量 除了中间那个 ,于是先算总重量减去右重量即可 复杂度为O(n)
    int pivotIndex(vector<int> &nums)
    {
        if (nums.size() == 0)
            return -1;
        int totalNum = 0;
        for (auto &i : nums)
            totalNum += i;
        int leftNum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (leftNum == totalNum - nums[i] - leftNum)
                return i;
            leftNum += nums[i];
        }
        return -1;
    }
};
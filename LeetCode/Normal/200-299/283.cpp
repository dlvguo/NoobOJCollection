#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int lastIndex = -1, lastZero = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                if (lastIndex == -1)
                    lastIndex = i + 1;
                while (lastIndex < nums.size() && !nums[lastIndex])
                {
                    lastIndex++;
                }
                // 遍历完返回
                if (lastIndex == nums.size())
                    return;
                swap(nums[i], nums[lastIndex]);
                lastIndex++;
            }
        }
    }
};
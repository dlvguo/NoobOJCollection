#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int totalHammingDistance(vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i < 31; i++)
        {
            int oN = 0;
            // 有时候类似题目 不需要用除法 用位运算指定位置 比除法快
            for (int i = 0; i < nums.size(); i++)
            {
                oN += (nums[i] >> i) & 1;
            }
            count += (nums.size() - oN) * oN;
        }
        return count;
    }
};
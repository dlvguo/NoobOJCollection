#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // 维护一个数组 up序列和down序列
    // 只需要俩个数即可
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return n;
        }
        int u = 1, d = 1;
        for (int i = 1; i < n; i++)
        {
            // 升序的序列 
            if (nums[i] > nums[i - 1])
            {
                u = max(u, d + 1);
            }
            // 降序
            else if (nums[i] < nums[i - 1])
            {
                d = max(u + 1, d);
            }
        }
        return max(u, d);
    }
};

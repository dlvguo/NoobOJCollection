#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void reverse(vector<int> &nums, int begin, int end)
    {
        while (begin < end)
        {
            int temp = nums[begin];
            nums[begin++] = nums[end];
            nums[end--] = temp;
        }
    }

    void rotate(vector<int> &nums, int k)
    {
        // 注意界限问题 避免超出
        k %= nums.size();
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
        reverse(nums, 0, nums.size() - 1);
    }
};
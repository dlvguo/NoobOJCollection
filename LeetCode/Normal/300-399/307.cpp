#include <bits/stdc++.h>
using namespace std;
class NumArray
{
public:
    vector<int> dp, nnums;
    int n;
    NumArray(vector<int> &nums)
    {
        nnums = nums;
        n = nums.size();
        dp.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            add(i + 1, nums[i]);
        }
    }

    int lowbit(int x)
    {
        return x & -x;
    }

    void add(int i, int val)
    {
        while (i <= n)
        {
            dp[i] += val;
            i += lowbit(i);
        }
    }

    void update(int index, int val)
    {
        //注意加的差异
        add(index + 1, val-nnums[index] );
        nnums[index] = val;
    }

    int sumRange(int left, int right)
    {
        right++;
        int lsum = 0, rsum = 0;
        while (left)
        {
            lsum += dp[left];
            left -= lowbit(left);
        }
        while (right)
        {
            rsum += dp[right];
            right -= lowbit(right);
        }
        return rsum - lsum;
    }
};

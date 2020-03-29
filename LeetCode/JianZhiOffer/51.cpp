#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //归并排序法
    int reversePairs(vector<int> &nums)
    {
        int sum = 0, step = 2, pre = 1, i;
        while (step <= nums.size())
        {
            //折半计算
            for (i = step; i <= nums.size(); i += step)
            {
                int last = i - 1;
                int first = last - pre, j = last; //注意因为排好序 所以j每次不需要从最后开始 所以剪枝
                for (int k = first; k >= i - step; k--)
                {
                    for (; j > first; j--)
                    {
                        if (nums[k] > nums[j])
                        {
                            sum += (j - first);
                            break;
                        }
                    }
                    if (j == first)
                        break;
                }
                sort(nums.begin() + (i - step), nums.begin() + i);
            }
            if (i - step < nums.size())
            {
                int last = nums.size() - 1;
                int first = i - step + pre - 1, j = last;
                if (first + 1 < nums.size())
                {
                    for (int k = first; k >= i - step; k--)
                    {
                        for (; j > first; j--)
                        {
                            if (nums[k] > nums[j])
                            {
                                sum += (j - first);
                                break;
                            }
                        }
                        if (j == first)
                            break;
                    }
                    sort(nums.begin() + (i - step), nums.end());
                }
            }
            pre = step;
            step *= 2;
        }
        if (nums.size() - pre > 0)
        {
            int last = nums.size() - 1;
            int first = pre - 1, j = last;
            for (int k = first; k >= 0; k--)
            {
                for (; j > first; j--)
                {
                    if (nums[k] > nums[j])
                    {
                        sum += (j - first);
                        break;
                    }
                }
                if (j == first)
                    break;
            }
        }
        return sum;
    }
};

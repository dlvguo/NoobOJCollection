#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxValue(int n, int index, int maxSum)
    {
        int left = 1, right = maxSum;
        while (left < right)
        {
            int mid = (left + right + 1) / 2;
            if (valid(mid, n, index, maxSum))
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }

    bool valid(int mid, int n, int index, int maxSum)
    {
        int left = index;
        int right = n - index - 1;
        return mid + cal(mid, left) + cal(mid, right) <= maxSum;
    }

    long cal(int big, int length)
    {
        if (length + 1 < big)
        {
            int small = big - length;
            return (long)(big - 1 + small) * length / 2;
        }
        else
        {
            int ones = length - (big - 1);
            return (long)big * (big - 1) / 2 + ones;
        }
    }
};

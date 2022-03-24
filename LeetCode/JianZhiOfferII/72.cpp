#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x <= 1)
            return x;
        long long left = 0, right = x;
        while (left <= right)
        {
            long long mid = (left + right) >> 1;
            if (x / mid == mid)
                return mid;
            else if (x / mid < mid)
            {
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return right;
    }
};
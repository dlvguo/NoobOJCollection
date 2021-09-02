#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int l = 0, r = num / 2 + 1;
        while (l <= r)
        {
            long long mid = (l + r) / 2;
            long long t = mid * mid;
            if (t == num)
                return true;
            else if (t < num)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};
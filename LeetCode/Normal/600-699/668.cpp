#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findKthNumber(int m, int n, int k)
    {
        int left = 1;
        int right = m * n;
        // [left, right]
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (count(m, n, mid) >= k)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }

    // 统计乘法表中有多少个小于等于 k 的数目
    int count(int m, int n, int k)
    {
        int res = 0;
        // 统计每行小于等于 k 的数目
        for (int i = 1; i <= m; ++i)
        {
            res += min(k / i, n);
        }
        return res;
    }
};

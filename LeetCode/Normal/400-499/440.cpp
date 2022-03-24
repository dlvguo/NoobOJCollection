#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findKthNumber(int n, int k)
    {
        int ans = 1;
        int cur = 1;
        while (k > 1)
        {
            int count = findNodes(ans, n);
            if (count < k)
            {
                k -= count;
                ans++;
            }
            else
            {
                ans *= 10;
                k--;
            }
        }
        return ans;
    }

    int findNodes(int l, long long n)
    {
        int res = 0;
        long long cur = l;
        long long next = l + 1;
        while (cur <= n)
        {
            res += min(n + 1, next) - cur;
            cur *= 10;
            next *= 10;
        }
        return res;
    }
};

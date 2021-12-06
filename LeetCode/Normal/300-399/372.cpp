#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int MOD = 1337;

    int quick_mul(int x, int n)
    {
        int res = 1;
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                res = (res * x) % MOD;
            }
            n >>= 1;
            x = (x * x) % MOD;
        }
        return res;
    }

    int superPow(int a, vector<int> &b)
    {
        int bn = (int)b.size();

        int res = 1;
        int x = a % MOD;
        for (int i = bn - 1; i > -1; i--)
        {
            int y = b[i];
            res = (res * quick_mul(x, y)) % MOD;
            x = quick_mul(x, 10);
        }
        return res;
    }
};
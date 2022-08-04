#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int mod = 1000000007;

public:
    int waysToStep(int n)
    {
        int n1 = 1, n2 = 2, n3 = 4;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 4;

        int ans = 0;

        for (int i = 4; i <= n; i++)
        {
            ans = n1 + n2 + n3;
            if (ans >= mod)
                ans -= mod;
            n1 = n2;
            n2 = n3;
            n3 = ans;
        }
        return ans;
    }
};
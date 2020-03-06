#include <bits/stdc++.h>
using namespace std;

int dp[58] = {0,1,2,3};

int cuttingRope(int n)
{
    if (n == 2)
        return 1;
    if (n == 3)
    {
        return 2;
    }
    for (int i = 4; i <= n; i++)
    {
        dp[i] = max(dp[i - 2] * 2, dp[i - 3] * 3);
    }

    return dp[n];
}
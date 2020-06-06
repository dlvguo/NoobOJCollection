#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double new21Game(int N, int K, int W)
    {
        double num1 = 0;
        if (K == 0)
            return 1.0;
        vector<double> dp(K + W);
        for (int i = K; i <= N && i < K + W; i++)
        {
            dp[i] = 1.0;
            num1 += dp[i];
        }
        for (int i = K - 1; i >= 0; i--)
        {
            dp[i] += num1 / W;
            num1 = num1 - dp[i + W] + dp[i];
        }
        return dp[0];
    }
};
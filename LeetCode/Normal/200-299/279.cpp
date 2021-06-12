#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int minn = INT_MAX;
            for (int j = 1; j * j <= i; j++)
            {
                minn = min(minn, f[i - j * j]);
            }
            f[i] = minn + 1;
        }
        return f[n];
    }
};
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
typedef __int64 ll;
ll dp[105][105][220];
ll a[105][105];
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                for (int k = 0; k <= 210; k++)
                {
                    dp[i][j][k] = -1000000000000000000ll;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                scanf("%I64d", &a[i][j]);
            }
        }
        dp[1][1][0] = a[1][1];
        for (int k = 1; k <= (n - 1) * 2; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                int c1 = 2 + k - i;
                if (c1 >= 1 && c1 <= n)
                    for (int j = 1; j <= n; j++)
                    {
                        int c2 = 2 + k - j;
                        if (c2 >= 1 && c2 <= n)
                        {
                            ll add = a[i][c1] + a[j][c2];
                            if (i == j && c1 == c2)
                                add /= 2;
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1] + add);
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + add);
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + add);
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - 1] + add);
                        }
                    }
            }
        }
        printf("%I64d\n", dp[n][n][(n - 1) * 2]);
    }
}

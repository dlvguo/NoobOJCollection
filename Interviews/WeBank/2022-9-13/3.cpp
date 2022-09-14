#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int mod = 998244353;

LL dp[501][12][12][12];

int main()
{
    int n, m;
    cin >> n >> m;
    dp[0][m + 1][m + 1][m + 1] = 1;

    int M = m +1;

    for (int i = 1; i <= n; i++)
    {
        for (int x = 1; x <= M; x++)
        {
            for (int y = 1; y <= M; y++)
            {
                for (int z = 1; z <= M; z++)
                {
                    for (int num = 1; num <= x && num < M; num++)
                        dp[i][num][y][z] = (dp[i][num][y][z] + dp[i - 1][x][y][z]) % mod;
                    for (int num = x + 1; num <= y && num < M; num++)
                        dp[i][x][num][z] = (dp[i][x][num][z] + dp[i - 1][x][y][z]) % mod;
                    for (int num = y + 1; num <= z && num < M; num++)
                        dp[i][x][y][num] = (dp[i][x][y][num] + dp[i - 1][x][y][z]) % mod;
                }
            }
        }
    }

    LL res = 0;
    for (int x = 1; x < M; x++)
    {
        for (int y = 1; y < M; y++)
        {
            for (int z = 1; z < M; z++)
            {
                res = (res + dp[n][x][y][z]) % mod;
            }
        }
    }
    cout << res << endl;
}
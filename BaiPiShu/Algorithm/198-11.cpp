#include <iostream>
using namespace std;

#define N 55
//题目没说清这就是一个01背包问题 有N座金矿 派出 每个金矿需要x人 有收益y 共派出M人 问能最大收益
//dp[i][j]表示包含i个矿j个人最大收益 m[i]表示金矿i需要多少人 w[i]表示金矿i收益多少

void TackBack(int dp[][], int n, int m, int man[])
{
    if (n == 1)
    {
        if (dp[n][m])
            cout << n;
    }
    if (dp[n - 1][m] == dp[n][m])
    {
        TackBack(dp, n - 1, m);
    }
    else
    {
        cout << n;
        TackBack(dp, n - 1, m - man[n]);
    }
}

void FindMax(int m[], int w[], int m, int n)
{
    int dp[N][N] = {0};
    for (int i = 1; i <= m; i++)
    {
        if (i <= m[1])
            dp[1][i] = 0;
        else
        {
            dp[1][i] = w[1];
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; i++)
        {
            if (j < m[i] || dp[i - 1][j] < dp[i - 1][j - m[i]] + w[i])
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = dp[i][j - m[i]] + w[i];
            }
        }
    }
}

//dp也可以压缩成一层因为每次只跟上层比较 dp[i]表示i 表示值为多少最大
int FindMax(int n, int m, int w[], int man[])
{
    int dp[N];
    for (int i =1; i <=n; i++)
    {
        for (int M= m; M>=man[i]; i++)
        {
            dp[M]=max(dp[M],dp[M-man[i]]+w[i]);
        }
    }
}
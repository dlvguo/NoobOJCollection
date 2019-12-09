#include <iostream>
using namespace std;
//背包问题 于是dp[i][w]表示 i个矿中 w个人最大价值
//最优子结构为 dp[i][w]={max(dp[i-1][w],dp[i-1][w-w[i]]+w[i])} w[i]表示第i个矿需要人数 c[i]表示第i个矿价值
#define N 10
#define M 5
void TrackBack(int m, int n, int dp[][N + 1], int w[]);
void SelectMaxValue(int w[], int c[])
{
    int dp[M + 1][N + 1] = {0};
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= M; i++)
        {
            dp[j][i] = 0;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (i >= w[1])
        {
            dp[1][i] = c[1];
        }
        else
        {
            dp[1][i] = 0;
        }
    }
    for (int i = 2; i <= M; i++)
    {
        for (int j = 1; j <= N; i++)
        {
            if (j < w[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                int temp = dp[i - 1][j - w[i]] + c[i];
                if (temp > dp[i - 1][j])
                {
                    dp[i][j] = temp;
                }
            }
        }
    }
    cout << dp[M][N] << endl;
    TrackBack(M, N, dp, w);
}
void TrackBack(int m, int n, int dp[][N + 1], int w[])
{
    if (m == 1)
    {
        if (dp[m][n])
            cout << 1 << endl;
    }
    else
    {
        if (dp[m - 1][n] != dp[m][n])
        {
            cout << m << " ";
            TrackBack(m - 1, n - w[m], dp, w);
        }
        else
        {
            TrackBack(m - 1, n, dp, w);
        }
    }
}

int main()
{
    int c[M + 1], w[M + 1];
    for (int i = 1; i <= M; i++)
    {
        //cin >> c[i] >> w[i];
    }
    SelectMaxValue(w, c);
}
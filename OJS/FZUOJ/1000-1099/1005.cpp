#include <iostream>
#include <cstdio>
#include <cstring>
#include<algorithm>
using namespace std;

const int MAX = 1e9;

int food[222];
//dp[i][j]表示i个餐馆k个仓库的最小值
int dp[222][33];
//sum[i][j]=i到j的距离
int sum[222][222];

int main()
{
	int n, m;
	int ans = 1;
	while (scanf("%d%d", &n, &m), n || m)
	{
		food[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &food[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			sum[i][i] = 0;
			for (int j = i + 1; j <= n; j++)
			{
				//计算距离
				sum[i][j] = sum[i][j - 1] + food[j] - food[(i + j) / 2];
			}
		}
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				dp[i][j] = MAX;
			}
		}
		dp[0][0] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int k = 1; k <= m; k++)
			{
				for (int j = 0; j < i; j++) //此层循环和上层循环哪个在外面都可以，因为dp[i][k]只和 dp[1][k-1]到dp[i-1][k-1]之间的有关
				{
					dp[i][k] = min(dp[i][k], dp[j][k - 1] + sum[j + 1][i]); //枚举从1到i-1之间的状态，进行更新dp[i][k]的值
				}
			}
		}
		printf("Chain %d\n", ans++);
		printf("Total distance sum = %d\n\n", dp[n][m]);
	}

	return 0;
}
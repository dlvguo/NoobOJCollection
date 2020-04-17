#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int N, map[1005][1005], visit[1005][1005], val[1000001], num, Max, ans;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

//边界和访问检查
bool check(int x, int y)
{
	if (x < 1 || y < 1 || x > N || y > N || visit[x][y])
		return false;
	return true;
}

//计算池塘的Val 此时-2 -3当作墙
void dfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int _x = x + dir[i][0], _y = y + dir[i][1];
		if (check(_x, _y))
		{
			visit[_x][_y] = 1;
			if (map[_x][_y] >= -1) //说明可以访问
			{
				if (map[_x][_y] > 0)
					ans += map[_x][_y];
				map[_x][_y] = num;
				dfs(_x, _y);
			}
		}
	}
}

//计算最大值 此时-3能通过
void dfsMax(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int _x = x + dir[i][0], _y = y + dir[i][1];
		if (check(_x, _y))
		{
			visit[_x][_y] = 1;
			//说明可以通过
			if (map[_x][_y] != -2)
			{
				int t = map[_x][_y];
				if (t >= 1)
					Max = Max < val[t] ? val[t] : Max;
				dfsMax(_x, _y);
			}
		}
	}
}
int main()
{
	while (scanf("%d", &N) != EOF)
	{
		int sx, sy;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				scanf("%d", &map[i][j]);
				visit[i][j] = 0;
				if (map[i][j] == -1)
				{
					sx = i;
					sy = j;
				}
			}
		//初始化NUM
		num = 1;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				//说明未访问
				if (visit[i][j] == 0 && map[i][j] >= -1)
				{
					ans = map[i][j] == -1 ? 0 : map[i][j];
					map[i][j] = num;
					visit[i][j] = 1;

					dfs(i, j);
					val[num++] = ans;
				}
			}
		}
		memset(visit, 0, sizeof(visit));
		Max = 0;
		visit[sx][sy] = 1;
		dfsMax(sx, sy);
		printf("%d\n", Max);
	}
}

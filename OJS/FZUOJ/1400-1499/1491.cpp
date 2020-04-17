#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

/*
	思路  第一步：因为-3会清空能量，一开始可以将-3和-2看成围墙，看看图中可以分割几块小图，类似LeetCode200计算岛屿数量,并给岛屿编号
    	  第二步：从机器人出发 再一次BFS求所能经过的最大值，-3看成通路
*/

int N, map[1005][1005], visit[1005][1005], val[1000005], num, res;
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

//边界和访问检查
bool check(int x, int y)
{
	if (x < 1 || y < 1 || x > N || y > N || visit[x][y])
		return false;
	return true;
}

struct Pos
{
	int x, y;
};

//第一次计算岛屿
void Bfs(int x, int y)
{
	Pos p;
	p.x = x;
	p.y = y;
	visit[x][y] = 1;
	if (map[x][y] > 0)
		val[num] = map[x][y];
	else
	{
		val[num] = 0;
	}
	map[x][y] = num;
	queue<Pos> q;
	q.push(p);
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int _x = p.x + dir[i][0], _y = p.y + dir[i][1];
			if (check(_x, _y))
			{
				visit[_x][_y] = 1;
				//非墙
				if (map[_x][_y] >= -1)
				{
					if (map[_x][_y] > 0)
						val[num] += map[_x][_y];
					map[_x][_y] = num;
					Pos t;
					t.x = _x;
					t.y = _y;
					q.push(t);
				}
			}
		}
	}
}

//第二次寻找最大值
void BfsSearchMax(int x, int y)
{
	Pos p;
	p.x = x;
	p.y = y;
	visit[x][y] = 1;
	res = 0;
	queue<Pos> q;
	q.push(p);
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int _x = p.x + dir[i][0], _y = p.y + dir[i][1];
			if (check(_x, _y))
			{
				visit[_x][_y] = 1;
				//非墙
				if (map[_x][_y] != -2)
				{
					if (map[_x][_y] > 0 && res < val[map[_x][_y]])
						res = val[map[_x][_y]];
					Pos t;
					t.x = _x;
					t.y = _y;
					q.push(t);
				}
			}
		}
	}
}

int main()
{
	while (scanf("%d", &N) != EOF)
	{
		int sx = 0, sy = 0;
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
		//num 地图编号 同一块小图编号相同
		num = 1;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				//说明未访问
				if (visit[i][j] == 0 && map[i][j] >= -1)
				{
					Bfs(i, j);
					num++;
				}
			}
		}
		memset(visit, 0, sizeof(visit));
		BfsSearchMax(sx, sy);
		printf("%d\n", res);
	}
}

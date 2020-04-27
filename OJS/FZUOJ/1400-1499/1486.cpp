#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
#define MAX 1005

//方向 对应上下左右
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

struct Pos
{
	int x, y, step, dir;
};

int m, n, visit[MAX][MAX];
char map[MAX][MAX];

//visit[x][y]==0表示墙和不能再访问的地方
bool check(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m || visit[x][y] == 0)
		return false;
	return true;
}

void bfs(int x, int y)
{
	queue<Pos> pq;
	//四个方向先拓展下
	for (int i = 0; i < 4; i++)
	{
		int _x = x + dir[i][0], _y = dir[i][1] + y;

		if (check(_x, _y))
		{ //说明可放入
			Pos p;
			p.x = _x;
			p.y = _y;
			p.step = 1;
			p.dir = i;
			visit[_x][_y] = 1;

			if (map[_x][_y] == 't')
			{
				return;
			}
			pq.push(p);
			//表示经过这里的最小访问次数
		}
	}

	while (pq.size())
	{
		Pos t = pq.front();
		pq.pop();

		for (int i = 0; i < 4; i++)
		{
			int _x = t.x + dir[i][0], _y = dir[i][1] + t.y;
			if (check(_x, _y))
			{ //说明可放入
				Pos p;
				p.x = _x;
				p.y = _y;
				p.dir = i;
				if (p.dir == t.dir)
					p.step = t.step;
				else
					p.step = t.step + 1;
				//未访问过
				if (visit[_x][_y] == -1 || p.step <= visit[_x][_y])
				{
					visit[_x][_y] = p.step;
					pq.push(p);
				}
			}
		}
	}
}

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		int sx, sy;
		getchar();
		for (int i = 0; i < n; i++)
		{
			scanf("%s", map[i]);
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == 'r')
				{
					sx = i;
					sy = j;
					//表示访问过为不可再访问
					visit[i][j] = 1;
				}
				else if (map[i][j] == '#')
				{
					//表示访问过为墙
					visit[i][j] = 1;
				}
				else //表示未访问过
				{

					visit[i][j] = 0;
				}
			}
		}
		bfs(sx, sy);
	}
}
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
	int x, y, step, commNum, dir;
};

int m, n, visit[MAX][MAX];
char map[MAX][MAX];

struct cmp
{
	bool operator()(Pos &x, Pos &y)
	{
		if (x.step == y.step)
			return x.commNum > y.commNum;
		return x.step > y.step;
	}
};

bool check(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m || visit[x][y])
		return false;
	return true;
}

void bfs(int x, int y)
{
	priority_queue<Pos, vector<Pos>, cmp> pq;
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
			p.commNum = 1;
			p.dir = i;
			if (map[_x][_y] == 't')
			{
				printf("%d\n", p.step);
				return;
			}
			pq.push(p);
			visit[_x][_y] = 1;
		}
	}

	while (pq.size())
	{
		Pos t = pq.top();
		pq.pop();
		cout << t.x << ' ' << t.y << ' ' << t.step << endl;
		//先扩展同方向的？
		int _x = t.x + dir[t.dir][0], _y = dir[t.dir][1] + t.y;
		if (check(_x, _y))
		{ //说明可放入
			Pos p;
			p.x = _x;
			p.y = _y;
			p.dir = t.dir;
			p.step = t.step;
			if (map[_x][_y] == 't')
			{
				printf("%d\n", p.step);
				return;
			}
			p.commNum = t.commNum + 1;
			pq.push(p);
			visit[_x][_y] = 1;
		}

		for (int i = 0; i < 4; i++)
		{
			if (i != t.dir)
			{
				_x = t.x + dir[i][0], _y = dir[i][1] + t.y;
				if (check(_x, _y))
				{ //说明可放入
					Pos p;
					p.x = _x;
					p.y = _y;
					p.dir = i;
					p.step = t.step + 1;
					if (map[_x][_y] == 't')
					{
						printf("%d\n", p.step);
						return;
					}
					p.commNum = t.commNum + 1;
					pq.push(p);
					visit[_x][_y] = 1;
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
					visit[i][j] = 1;
				}
				else if (map[i][j] == '#')
				{
					visit[i][j] = 1;
				}
				else
				{
					visit[i][j] = 0;
				}
			}
		}
		bfs(sx, sy);
	}
}
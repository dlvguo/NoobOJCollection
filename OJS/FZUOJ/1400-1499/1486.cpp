#define _CRT_SECURE_NO_WARNINGS
#define MAX 1005
#include <queue>
#include <cstring>
#include <stdio.h>
using namespace std;

//方向 对应上下左右
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

struct Pos
{
	int x, y, step, dir;
	bool operator<(const Pos &b) const { return step > b.step; }
};

int m, n, visit[MAX][MAX][4];

char map[MAX][MAX];

void bfs(int x, int y)
{
	priority_queue<Pos> pq;

	Pos p;
	p.dir = -1;
	p.x = x;
	p.y = y;
	p.step = 0;
	pq.push(p);
	while (pq.size())
	{
		p = pq.top();
		pq.pop();
		if (map[p.x][p.y] == 't')
		{
			printf("%d\n", p.step);
			return;
		}
		//四个方向先拓展下
		for (int i = 0; i < 4; i++)
		{
			int _x = p.x + dir[i][0], _y = p.y + dir[i][1];
			//这个方向一直拓展
			if (_x >= 0 && _y >= 0 && _x < n && _y < m && map[_x][_y] != '#')
			{
				if (visit[_x][_y][i] == 0)
					continue;
				visit[_x][_y][i] = 1;
				Pos t;
				t.x = _x;
				t.y = _y;
				t.dir = i;
				if (i == t.dir)
					t.step = p.step;
				else
					t.step = p.step + 1;
				pq.push(t);
			}
		}
	}
}

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		int sx, sy;
		//getchar();
		memset(visit, 0, sizeof(visit));
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
					visit[i][j][0] = 1;
					visit[i][j][1] = 1;
					visit[i][j][2] = 1;
					visit[i][j][3] = 1;
				}
			}
		}
		bfs(sx, sy);
	}
}
#include<iostream>
#include<cstring>
#include<queue>
#include<stdio.h>
using namespace std;

typedef struct Node {
	int x, y;
	int time;
	friend bool operator<(Node n1, Node n2) {
		return n1.time>n2.time;
	}
}node;
struct Point {
	int x, y;
	int n;
}point[100][100], Copy[100][100];
int dis[4][2] = { 0,1,0,-1,1,0,-1,0 }, visit[100][100], N, M;
char mg[100][100];
int bfs() {
	priority_queue<Node>q;
	Node start, next;
	start.x = 0;
	start.y = 0;
	start.time = 0;
	visit[0][0] = 1;
	q.push(start);
	while (q.size())
	{
		start = q.top();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x1, y1;
			x1 = start.x + dis[i][0];
			y1 = start.y + dis[i][1];
			if (x1 < 0 || x1 == N || y1 < 0 || y1 == M || visit[x1][y1] == 1 || mg[x1][y1] == 'X')
				continue;
			next.x = x1;
			next.y = y1;
			if (mg[x1][y1] == '.')
				next.time = start.time + 1;
			else
				next.time = start.time + 1 + mg[x1][y1] - '0';
			point[x1][y1].x = start.x;
			point[x1][y1].y = start.y;
			point[x1][y1].n = next.time - start.time-1;
			visit[x1][y1] = 1;
			if (x1 == N - 1 && y1 == M - 1)
				return	next.time;
			q.push(next);
		}
	}
	return 0;
}
void dfs(int x, int y,int cont) {
	int  n;
	n = point[x][y].n;
	if (!(point[x][y].x == 0 && point[x][y].y == 0))
	dfs(point[x][y].x, point[x][y].y,cont-n-1);
	int y1 = cont;
	if (n)
	{
		y1 = cont - n;
		printf("%ds:(%d,%d)->(%d,%d)\n",y1,point[x][y].x, point[x][y].y, x, y);
		while (n--)
		{
			y1++;
			printf("%ds:FIGHT AT (%d,%d)\n",y1, x, y);
		}
	}
	else
	{
		printf("%ds:(%d,%d)->(%d,%d)\n",cont, point[x][y].x, point[x][y].y, x, y);
	}
}

int main() {
	while (cin >> N >> M) {
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i<N; i++)
			for (int j = 0; j<M; j++)
				cin >> mg[i][j];
		int n = bfs();
		if (n)
		{
			printf("It takes %d seconds to reach the target position, let me show you the way.\n", n);
			dfs(N - 1, M - 1,n);
		}
		else
			cout << "God please help our poor hero." << endl;
		cout << "FINISH\n";
			}
	
	return 0;
}


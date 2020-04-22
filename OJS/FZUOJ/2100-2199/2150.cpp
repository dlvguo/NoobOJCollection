#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

char map[12][12];
int visit[11][11];
//方向
int dir[4][2] = {0, 1, 0, -1, -1, 0, 1, 0};
int n, m, pindex, grassNum;

struct Pos
{
    int x, y;
} poses[105];

int bfs(int ap, int bp)
{
    memset(visit, 0, sizeof(visit));
    int ans = 0, step = -1;
    queue<Pos> pq;
    pq.push(poses[ap]);
    pq.push(poses[bp]);
    //记录访问
    visit[poses[ap].x][poses[ap].y] = 1;
    visit[poses[bp].x][poses[bp].y] = 1;
    while (pq.size())
    {
        //多点BFS
        int count = pq.size();
        ans += count;
        while (count--)
        {
            Pos p = pq.front();
            pq.pop();
            for (int i = 0; i < 4; i++)
            {
                int _x = p.x + dir[i][0], _y = p.y + dir[i][1];
                if (_x < 1 || _x > n || _y < 1 || _y > m || visit[_x][_y])
                    continue;
                visit[_x][_y] = 1;
                if (map[_x][_y] == '#')
                {
                    Pos temp;
                    temp.x = _x;
                    temp.y = _y;
                    pq.push(temp);
                }
            }
        }
        step++;
    }
    if (ans == grassNum)
        return step;
    return 10000;
}

int main()
{

    int t;
    scanf("%d", &t);
    for (int num = 1; num <= t; num++)
    {
        //暴力bfs数据量不大
        scanf("%d%d", &n, &m);
        getchar();
        pindex = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%c", &map[i][j]);
                if (map[i][j] == '#')
                {
                    Pos p;
                    p.x = i;
                    p.y = j;
                    poses[pindex++] = p;
                }
            }
            getchar();
        }
        grassNum = pindex;

        int total = 10000;
        for (int i = 0; i < pindex - 1; i++)
        {
            for (int j = i + 1; j < pindex; j++)
            {
                total = min(bfs(i, j), total);
            }
        }

        if (grassNum == 1)
            total = 0;
        else if (total == 10000)
            total = -1;
        printf("Case %d: %d\n", num, total);
    }

    return 0;
}
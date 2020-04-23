#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

/*
    思路：简单的BFS水题  可以用多源BFS一开始将1放入然后 然后一次次遍历即可 
    本来没必要记录但是有个坑以前没考虑到 请翻到最后
*/

struct Pos
{
    int x, y;
};

int main()
{
    //多源BFS
    int n, m;
    char map[185][185];
    int visit[185][185];
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

    while (scanf("%d%d", &n, &m) != EOF)
    {
        queue<Pos> pq;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == '1')
                {
                    visit[i][j] = 0;
                    Pos t;
                    t.x = i;
                    t.y = j;
                    pq.push(t);
                }
                else
                {
                    visit[i][j] = -1;
                }
            }
        }

        //BFS即可
        int step = 1;
        while (!pq.empty())
        {
            int count = pq.size();
            while (count--)
            {
                Pos p = pq.front();
                pq.pop();
                for (int i = 0; i < 4; i++)
                {
                    int _x = dir[i][0] + p.x, _y = dir[i][1] + p.y;
                    if (_x < 1 || _y < 1 || _x > n || _y > m || visit[_x][_y] != -1)
                        continue;
                    visit[_x][_y] = step;
                    Pos t;
                    t.x = _x;
                    t.y = _y;
                    pq.push(t);
                }
            }
            step++;
        }
        for (int i = 1; i <= n; i++)
        {
            printf("%d", visit[i][1]);
            for (int j = 2; j <= m; j++)
            {
                printf(" %d", visit[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

const int Max = 1005;

const int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

struct Pos
{
    int x, y;
};

char map[Max][Max];
int visit[Max][Max], n;

int bfs(int x, int y)
{
    queue<Pos> pq;
    Pos p;
    p.x = x;
    p.y = y;
    pq.push(p);
    int step = 0;
    while (pq.size())
    {
        int count = pq.size();
        while (count--)
        {
            p = pq.front();
            pq.pop();
            for (int i = 0; i < 4; i++)
            {
                int _x = p.x + dir[i][0], _y = p.y + dir[i][1];
                if (_x < 0 || _y < 0 || _x >= n || _y >= n || visit[_x][_y])
                    continue;
                visit[_x][_y] = 1;
                if (map[_x][_y] == 'E')
                    return step + 1;
                else if (map[_x][_y] == '.')
                {
                    Pos t;
                    t.x = _x;
                    t.y = _y;
                    pq.push(t);
                }
            }
        }
        step++;
    }
    return -1;
}

int main()
{
    while (~scanf("%d", &n))
    {
        int x, y;
        getchar();
        for (int i = 0; i < n; i++)
        {
            scanf("%s", map[i]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (map[i][j] == 'S')
                {
                    visit[i][j] = 1;
                    x = i;
                    y = j;
                }
                else
                {
                    visit[i][j] = 0;
                }
            }
        }
        printf("%d\n", bfs(x, y));
    }
}
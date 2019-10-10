#include <iostream>
#include <queue>
using namespace std;

char map[22][22];
bool visit[22][22];

struct pos
{
    int x, y;
    int len;
};

int m, n, pnum;
int dist[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
pos plist[400];

bool BorderJudge(int x, int y)
{
    if (x < 0 || y < 0 || x == m || y == n)
        return true;
    return false;
}

void bfs(int x, int y)
{
    visit[x][y] = true;
    queue<pos> q;
    pos p;
    p.x = x;
    p.y = y;
    q.push(p);
    while (!q.empty())
    {
        pos p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x1 = p.x + dist[i][0];
            int y1 = p.y + dist[i][1];

            if (visit[x1][y1] || BorderJudge(x1, y1))
                continue;
            visit[x1][y1] = true;
            char c = map[x1][y1];
            if (c == '.')
            {
                pos newp;
                newp.x = x1;
                newp.y = y1;
                newp.len = p.len + 1;
            }
            else if (c == '*')
                continue;
            else if (c == 'T')
            {
                cout << p.len + 1 << endl;
                return;
            }
            else if (c == '|')
            {
                //说明上下俩层？
                int y2 = 0;
                if (y1 == p.y)
                {
                    y1 = y1 + 1;
                    if (!BorderJudge(x1, y1 - 1) && !visit[x1][y1 + 1])
                    {
                        pos newp;
                        newp.x = x1;
                        newp.y = y1 + 1;
                        newp.len = p.len + 1;
                        q.push(newp);
                        visit[x1][y1 + 1] = true;
                    }
                    if (!BorderJudge(x1, y1 - 1) && !visit[x1][y1 - 1])
                    {
                        pos newp;
                        newp.x = x1;
                        newp.y = y1 - 1;
                        newp.len = p.len + 1;
                        q.push(newp);
                        visit[x1][y1 - 1] = true;
                    }
                    else if (y1 < p.y && !BorderJudge(x1, y1 - 1) && !visit[x1][y1 - 1])
                    {
                        pos newp;
                        newp.x = x1;
                        newp.y = y1 - 1;
                        newp.len = p.len + 1;
                        q.push(newp);
                        visit[x1][y1 - 1] = true;
                    }
                    else if (!BorderJudge(x1, y1 + 1) && !visit[x1][y1 + 1])
                    {
                        pos newp;
                        newp.x = x1;
                        newp.y = y1 + 1;
                        newp.len = p.len + 1;
                        q.push(newp);
                        visit[x1][y1 + 1] = true;
                    }
                }
            }
            else {
                
                if (y1 == p.y)
                {
                    if (!BorderJudge(x1, y1 - 1) && !visit[x1][y1 + 1])
                    {
                        pos newp;
                        newp.x = x1;
                        newp.y = y1 + 1;
                        newp.len = p.len + 1;
                        q.push(newp);
                        visit[x1][y1 + 1] = true;
                    }
                    if (!BorderJudge(x1, y1 - 1) && !visit[x1][y1 - 1])
                    {
                        pos newp;
                        newp.x = x1;
                        newp.y = y1 - 1;
                        newp.len = p.len + 1;
                        q.push(newp);
                        visit[x1][y1 - 1] = true;
                    }
                    else if (y1 < p.y && !BorderJudge(x1, y1 - 1) && !visit[x1][y1 - 1])
                    {
                        pos newp;
                        newp.x = x1;
                        newp.y = y1 - 1;
                        newp.len = p.len + 1;
                        q.push(newp);
                        visit[x1][y1 - 1] = true;
                    }
                    else if (!BorderJudge(x1, y1 + 1) && !visit[x1][y1 + 1])
                    {
                        pos newp;
                        newp.x = x1;
                        newp.y = y1 + 1;
                        newp.len = p.len + 1;
                        q.push(newp);
                        visit[x1][y1 + 1] = true;
                    }
                }
            }
        }
    }
}

int main()
{
    while (cin >> m >> n)
    {
        int x, y;
        pnum = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char a;
                cin >> a;
                map[i][j] = a;
                if (a == 'T')
                {
                    x = i;
                    y = j;
                }
                if (a == '|' || a == '-')
                {
                    pos p;
                    p.x = i;
                    p.y = y;
                    plist[pnum++] = p;
                }
                visit[i][j] = false;
            }
            bfs(x, y);
        }
    }
}
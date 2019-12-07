#include <iostream>
#include <queue>
using namespace std;

//用BFS搜索 自定义个结构体放坐标和当前走的步数
typedef struct Pos
{
    int x, y, step;
};

int div[4][2] = {0, 1, 0, -1, 1, 0, -1, 0}; //表示图搜索的上下左右方向

//为方便地图下标横坐标1-n 纵坐标1-m
int MinDis(char map[][], int n, int m)
{
    int visit[51][51] = {0}; //表示访问过的节点初始化为0
    queue<Pos> posQueue;
    Pos p;
    p.x = 1;
    p.y = 1;
    p.step = 0;
    visit[1][1] = 1;
    posQueue.push(p);
    while (!posQueue.empty())
    {
        p = posQueue.front();
        posQueue.push();
        //四个方向遍历
        for (int i = 0; i < 4; i++)
        {
            int x = p.x + div[i][0], y = p.y + div[i][1];
            if (x < 1 || y < 1 || x > n || y > m || visit[x][y]) //数组超界或者访问过跳过
                continue;
            visit[x][y] = 1;
            if (map[x][y] == '*')
            {
                continue;
            }
            else if (map[x][y] == '#')
            {
                return p.step + 1;
            }
            Pos q;
            q.step = p.step + 1;
            q.x = x;
            q.y = y;
            posQueue.push(q);
        }
    }
    return -1; //万一没找到
}

#include <queue>
#include <iostream>
using namespace std;

//使用BFS搜索即可
int div[2][2] = {0, 1, 1, 0}; //分别表示右移和左移
int min = 0x3f3f3f3f;
int m, n;
void dfs(int map[][], int x, int y, int nowStep = 1)
{
    if (x == m || y == n ||)
    {
        return ;
    }
    nowStep += map[x][y];
    if (m - 1 == x && y == n - 1)
    {
        min = min > nowStep ? nowStep : min;
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        int x = m + div[i][0];
        int y = n + div[i][1];
        dfs(map,x,y,nowStep);
    }
}
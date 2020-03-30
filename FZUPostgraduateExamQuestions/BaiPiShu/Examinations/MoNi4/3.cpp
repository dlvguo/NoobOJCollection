#include <iostream>
using namespace std;
#define N 666
#define M 666
int visit[N + 1][M + 1];                                                //表示遍历过的数组
int div[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, -1, -1, -1, 1, 1, -1, 1, 1}; //表示八个方向遍历
//思路 依次遍历图每个未访问的点 找到如果是*即进入dfs 最大连通 即算一个水池
void dfs(char **map, int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        int x1 = x + div[i][0];
        int y1 = x + div[i][1];
        if (x1 < 1 || y1 < 1 || x1 > N || y1 > M || visit[x1][y1]) //数组越界
            continue;
        visit[x1][y1] = 1;
        if (map[x1][y1] == '*')
        { //说明是积水 继续dfs
            dfs(map, x1, y1);
        }
    }
}

int FigurePool(char **map)
{
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (visit[i][j])
                continue;
            visit[i][j] = 1;
            if (map[i][j] == '*')
                dfs(map, i, j);
        }
    }
}
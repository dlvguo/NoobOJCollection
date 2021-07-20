#include <bits/stdc++.h>
using namespace std;

char _map[1005][1005];

int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

int n, m, totalnum = 0;

void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int _x = dir[i][0] + x;
        int _y = dir[i][1] + y;
        if (_x < 0 || _y < 0 || _x > n + 1 || _y > m + 1 || _map[_x][_y] == '1')
            continue;
        if (_map[_x][_y] == '0')
            totalnum++;
        _map[_x][_y] = '1';
        dfs(_x, _y);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    getchar();
    //做1-n的映射
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%c", &_map[i][j]);
        }
        cin.get();
    }
    //简单的话就是扩大一层做 否则可能忽略某些元素
    dfs(0, 0);
    cout << totalnum << endl;
}
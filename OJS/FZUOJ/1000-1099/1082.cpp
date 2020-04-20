#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int map[105][105], n, m;

int dfs(int x, int y)
{
    int res = 0;
    for (int i = 0; i < 4; i++)
    {
        int _x = dir[i][0] + x, _y = dir[i][1] + y;
        if (_x < 1 || _y < 1 || _x > n || y > m || map[_x][_y] == 2) //代表访问过和越界
            continue;
        if (map[_x][_y] == 1)
        {
            map[_x][_y] = 2;
            res++;
            res += dfs(_x, _y);
        }
        else
        {
            map[_x][_y] = 2;
        }
    }
    return res;
}

int main()
{
    while (cin >> n >> m, n + m)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> map[i][j];
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (map[i][j] == 1)
                {

                    map[i][j] = 2;
                    int temp = dfs(i, j) + 1;
                    ans = max(temp, ans);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
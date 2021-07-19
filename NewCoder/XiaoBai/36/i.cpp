#include <bits/stdc++.h>
using namespace std;

int visit[1005][1005] = {0};
char _map[1005][1005];

int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

int n, m, totalnum = 0;

void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int _x = dir[i][0] + x;
        int _y = dir[i][1] + y;
        if (_x < 0 || _y < 0 || _x >= n || _y >= m || visit[_x][_y])
            continue;
        if (_map[_x][_y] == '1')
        {
            visit[_x][_y] = 1;
            continue;
        }
        else
        {
            visit[_x][_y] = 1;
            if (_map[_x][_y] == '0')
                totalnum++;
            dfs(_x, _y);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    getchar();
    for (int i = 0; i < n; i++)
    {
        cin>>_map[i];
    }
    //四个边界面搜索
    for (int j = 0; j < m; j++)
    {
        if (visit[0][j])
            continue;
        if (_map[0][j] == '1')
            visit[0][j] = 1;
        else
        {
            visit[0][j] = 1;

            if (_map[0][j] == '0')
            {
                totalnum++;
            }
            dfs(0, j);
        }

        if (visit[n - 1][j])
            continue;
        if (_map[n - 1][j] == '1')
            visit[n - 1][j] = 1;
        else
        {
            visit[n - 1][j] = 1;

            if (_map[n - 1][j] == '0')
            {
                totalnum++;
            }
            dfs(n - 1, j);
        }
    }

    //四个边界面搜索
    for (int j = 1; j < n - 1; j++)
    {
        if (visit[j][0])
            continue;
        if (_map[j][0] == '1')
            visit[j][0] = 1;
        else
        {
            visit[j][0] = 1;

            if (_map[j][0] == '0')
            {
                totalnum++;
            }
            dfs(j, 0);
        }


        if (visit[j][m - 1])
            continue;
        if (_map[j][m - 1] == '1')
            visit[j][m - 1] = 1;
        else
        {
            visit[j][m - 1] = 1;

            if (_map[j][m - 1] == '0')
            {
                totalnum++;
            }
            dfs(j, m - 1);
        }
    }
    cout << totalnum << endl;
}
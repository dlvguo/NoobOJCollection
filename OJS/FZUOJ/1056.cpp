#include <iostream>
using namespace std;

int n, m;
int dir[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};

int digmap[101][101];
char map[101][101];
void dfs(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        int _x = dir[i][0] + x, _y = dir[i][1] + y;
        if (x < 0 || y < 0 || _x >= m || _y >= n || digmap[_x][_y] != -1)
        {
            continue;
        }
        if (map[_x][_y] == '*')
        {
            digmap[x][y]++;
        }
        else
        {
            digmap[_x][_y] = 0;
            dfs(_x, _y);
        }
    }
}

int main()
{
    while (cin >> m >> n, m || n)
    {
        getchar();
        for (int i = 0; i < m; i++)
        {

            for (int j = 0; j < n; j++)
            {
                digmap[i][j] = -1; //代表未访问过
                scanf("%c", &map[i][j]);
            }
            getchar();
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (digmap[i][j] == -1)
                {
                    if (map[i][j] == '*')
                        printf("%c", map[i][j]);
                    else
                    {
                        digmap[i][j] = 0;
                        dfs(i, j);
                        printf("%d", digmap[i][j]);
                    }
                }
                else
                {
                    printf("%d", digmap[i][j]);
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

char map[101][101];

struct Animal
{
    int x, y;
    //1 上 2右 3下 4左
    int _dir;
};

int dir[5][2] = {{0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main()
{
    int n;
    scanf("%d", &n);
    int sum;
    Animal cat, mouse;
    while (n--)
    {
        getchar(); //注意细节 每行多了一个回车 FUCK
        sum = 0;
        for (int i = 1; i < 11; i++)
        {
            for (int j = 1; j < 11; j++)
            {
                scanf("%c", &map[i][j]);
                if (map[i][j] == 'c')
                {
                    cat.x = i;
                    cat.y = j;
                    cat._dir = 1;
                }
                if (map[i][j] == 'm')
                {
                    mouse.x = i;
                    mouse.y = j;
                    mouse._dir = 1;
                }
            }
            getchar();
        }

        int _x, _y;
        while (cat.x != mouse.x || cat.y != mouse.y)
        {
            _x = cat.x + dir[cat._dir][0];
            _y = cat.y + dir[cat._dir][1];
            if (_x < 1 || _y < 1 || _x > 10 || _y > 10 || map[_x][_y] == '*')
            {
                cat._dir++;
                if (cat._dir > 4)
                    cat._dir = 1;
            }
            else
            {
                cat.x = _x;
                cat.y = _y;
            }
            _x = mouse.x + dir[mouse._dir][0];
            _y = mouse.y + dir[mouse._dir][1];
            if (_x < 1 || _y < 1 || _x > 10 || _y > 10 || map[_x][_y] == '*')
            {
                mouse._dir++;
                if (mouse._dir > 4)
                    mouse._dir = 1;
            }
            else
            {
                mouse.x = _x;
                mouse.y = _y;
            }
            sum++;
            if (sum > 500)
            {
                sum = 0;
                break;
            }
        }

        cout << sum << endl;
        /* code */
    }
}
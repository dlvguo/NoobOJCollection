#include <iostream>
using namespace std;
//用一个并查集存放最后计算有几个集合及几个朋友圈
//输入若是朋友则合并 若如输入xy是敌人则让x与y的敌人合并 y与x的敌人合并
//用enemy[i][1]存放i的第一个敌人 enemy[i][0]表示敌人个数
//设置集合union[i]初始化union[i]==i表示为根节点

int find(int un[], int x)
{
    if (un[x] == x)
    {
        return x;
    };
    return find(un, un[x]);
}

void Union(int un[], int x, int y)
{
    int root = find(un, y);
    un[y] = x;
}

int FigureFriend(int n, int m)
{
    int *un = new int[n + 1];
    int **enemy = new *int[m + 1];
    for (int i = 0; i <= m; i++)
    {
        (*enemy) = new int[m + 1];
    }
    while (m--)
    {
        int x, y, p;
        cin >> x >> y >> p;
        if (p == 0)
        { //不是敌人
            Union(un, x, y);
        }
        else
        {
            //先让x与y的敌人联合 y与x的敌人联合
            for (int i = 1; i <= enemy[x][0]; i++)
            {
                Union(un, y, enemy[x][i]);
            }
            for (int i = 1; i <= enemy[y][0]; i++)
            {
                Union(un, x, enemy[y][i]);
            }
            enemy[x][++enemy[x][0]] = y;
            enemy[y][++enemy[y][0]] = x;
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (un[i] == i)
            sum++;
    }
    return sum;
}
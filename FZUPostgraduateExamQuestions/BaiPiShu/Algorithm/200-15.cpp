#include <iostream>
using namespace std;
//用数组pool表示n个湖泊 pool[1]=2 说明湖泊1填的话需要2个格子
//用dfs遍历寻找湖泊 visit[][]表示访问过的点初始化为0 map[][]表示地图
int m, n, visit[][], pool[], poolcount;
int dis[][] = {0, -1, 0, 1, -1, 0, 1};
//当找到一个点是'.'时候用dfs计算数字 如果返回-1 说明不是湖泊 返回0说明这边是'*'  返回大于0的时候说明是湖泊并存储他的值
int dfs(char map[][], int x, int y)
{
    //
    if (x < 0 || y < 0 || y >= m || x >= n)
        return -1;
    if (map[x][y] == '*' || visit[x][y])
    {
        visit[x][y] = 1;
        return 0;
    }
    int sum = 1;
    visit[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        //从四个方向递归
        int temp = dfs(map[][], x + div[i][0], y + div[i][1]);
        if (temp == -1) //说明不是湖泊
            return -1;
        sum += temp;
    }
    return sum;
}

int ClearNum(char map[][], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; i++)
        {
            if (map[i][j] == '*')
                visit[m][n] = 1;
            else
            {
                int k = dfs(map, i, j);
                if (k != -1)
                    pool[poolcount++] = k;
            }
        }
    }
    //将湖泊从小到大排序
    Sort(pool, 1, poolcount);
    int sum = 0;
    for (int i = 0; i < poolcount; i++)
    {
        sum += pool[cout];
    }
    return sum;
}
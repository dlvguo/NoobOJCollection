#include <iostream>
using namespace std;

//使用并查集 若是好友则合并 若不是好友则看他的好友是否是同一个社团
#define N 999

int f[N + 1], visit[N + 1];
//合并xy
void Merge(int x, int y)
{
    //若f[x]==x 表示为根节点 否则f[y]指向的父节点也指向x的集合
    if (f[y] != y)
        Merge(x, f[y]);
    f[y] = f[x];
}

void FigureNum()
{
    int n, m, x, y, visit[N], ans = 0;
    cin >> n >> m;
    //初始化每个根节点
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
        //代表是否为根节点
        visit[i] = 0;
    }

    while (m--)
    {
        cin >> x >> y;
        //合并即可
        Merge(x, y);
    }
    for (int i = 1; i <= n; i++)
    {
        int index = find(i);
        if (!visit[index])
        {
            ans++;
            visit[index]=1;
        }
    }
    cout << ans++;
}

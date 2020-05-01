#include <iostream>
using namespace std;
#define MAX 1005

/*
    思路：最小生成树的题目 每个字符串看成一个点 各点之间的权值就看 汉明距离*w与字符串长度m之间小的那个值 使用prim算法
*/

char strs[MAX][15];
//表示边权值
int edges[MAX][MAX];
//表示该点是否加入集合
int vis[MAX];
//表示该点到集合S的最小距离
int dist[MAX];
int n, m, w;

int hamming(int i, int j)
{
    int sum = 0;
    for (int index = 0; index < m; index++)
    {
        if (strs[i][index] != strs[j][index])
            sum++;
    }
    return sum;
}

int prim()
{
    int ans = 0;
    //从0点计算用Prim
    vis[0] = 1;
    dist[0] = 0;
    for (int i = 1; i < n; i++)
    {
        vis[i] = 0;
        dist[i] = edges[0][i];
    }
    //n个节点选择n-1条边
    for (int i = 1; i < n; i++)
    {
        int c, d = 20;
        for (int j = 1; j < n; j++)
        {
            if (!vis[j] && d > dist[j])
            {
                d = dist[j];
                c = j;
            }
        }
        vis[c] = 1;
        ans += d;
        //更新dist
        for (int j = 1; j < n; j++)
        {
            if (!vis[j] && edges[c][j] < dist[j])
            {
                dist[j] = edges[c][j];
            }
        }
    }
    return ans;
}

int main()
{
    while (~scanf("%d%d%d", &n, &m, &w))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%s", strs[i]);
        }
        //计算边
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int h = hamming(i, j) * w;
                edges[i][j] = edges[j][i] = h > m ? m : h;
            }
        }
        printf("%d\n", prim() + m);
    }
}
#include <iostream>
using namespace std;
//用笛捷斯卡最短路径算法
//结构体用邻接矩阵的图
//如果情况真的是那么个情况暴力DFS
#define INF 0x3f3f3f3f;
typedef struct Graph
{
    int vertexnum, edgenum;
    int **edges;
    char *v;
};

int MiniPrice(Graph g)
{
    //Dist表示S到各点的最短路径 找到至D的即可 设V0=S
    int *dist = new[g.vertexnum];
    int *path = new[g.vertexnum];
    int *visit = new[g.vertexnum];
    dist[0] = path[0] = 0;
    visit[0] = 1;
    for (int i = 1; i < g.vertexnum; i++)
    {
        dist[i] = g.edges[0][i];
        path[i] = 0;
    }
    //dist=0 表示路已经找到
    int n = g.vertexnum - 1;
    while (n--)
    {
        //先找dist[]中最短路线
        int min = INF;
        int minindex = -1;
        for (int i = 1; i < g.vertexnum; i++)
        {
            if (!visit[i] && min > dist[i])
            {
                min = dist[i];
                minindex = i;
            }
        }
        if (g.v[minindex] == 'S')
        {
            return dist[minindex];
        }
        visit[minindex] = 1;
        //更新节点
        for (int i = 1; i < g.vertexnum; i++)
        {
            if (!visit[i] && g.edges[minindex][i] != INF) //说明连接
            {
                int temp=dist[minindex]+g.edges[minindex][i];
                if(dist[i]>temp){
                    dist[i]=temp;
                }
            }
        }
    }
    return -1;
}
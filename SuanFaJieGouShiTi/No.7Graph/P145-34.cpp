#include <iostream>
using namespace std;

#define Inf int.Maxvalue //表示连接不存在
typedef struct arcnode
{
    arcnode *next;
    int adjvex;
    int weight;
} * ArcNode;

//名字不标准后期记一记 这都小事情
typedef struct Graph
{
    int vertexnum, edgesnum;
    ArcNode vnodes[];
};

//找v到i的点的距离 若不存在返回-1
int FindDistance(Graph g, int v, int i)
{
    ArcNode p = g.vnodes[v];
    while (p)
    {
        if (p->adjvex == i)
            return p->weight;
        p = p->next;
    }
    return Inf;
}

void Djsik(Graph g, int v)
{
    //表示顶点v到i的最短距离
    int *dist = new int[g.vertexnum + 1];
    //表示上一路径用于回溯找最短路径遍历的节点
    int *prev = new int[g.vertexnum + 1];
    //表示遍历过的
    int *visit = new int[g.vertexnum + 1];
    //初始化
    for (int i = 1; i <= g.vertexnum; i++)
    {
        dist[i] = FindDistance(g, v, i);
        prev[i] = v;
    }
    dist[v] = Inf; //设个最大值方便下面处理
    for (int i = 2; i <= g.vertexnum; i++)
    {
        int index = v;
        for (int j = 1; j <= g.vertexnum; j++)
        {
            if (visit[j])
                continue;
            if (dist[index] > dist[j])
                index = j;
        }
        //说明不连通
        if(index==v){
            break;
        }
        visit[index]=1;
        //若找到更新dist
        for (int j = 1; j <=g.vertexnum ; j++)
        {
            if(visit[j])
            continue;
            int temp=dist[index]+FindDistance(g,index,j);
            if(dist[i]>temp){
                dist[i]=temp;
                prev[i]=index;
            }
        }   
    }
}
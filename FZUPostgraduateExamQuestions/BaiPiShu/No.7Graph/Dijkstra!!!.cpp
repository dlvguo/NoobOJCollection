#include <iostream>
using namespace std;

#define N 100
#define V 10
#define INF -1
//用邻接矩阵表示
typedef struct Graph
{
    int vexnum, edgesnum;
    int edges[N+1][N+1];//若边不存在默认INF
    char vexs[V+1];
};

void Dijkstra(Graph g)
{
    //表示 vo - vi的长度
    int *dist = new int[g.vexnum+1];
    //表示 当前选中节点的前驱节点用于输出路径
    int *prev = new int[g.vexnum+1];
    //表示是否找到最短路径
    bool *flag=new int[g.vexnum+1];
    //初始化
    for (int i = 2; i <= g.vexnum; i++)
    {
        dist[i]=g.edges[1][i];
        prev[i]=1;
    }
    //有n个节点故只需要循环N-1次
    for (int i = 1; i < g.vexnum; i++)
    {
        //从未访问中找出最短的目标点p
        int p=-1;
        for (int i = 2; i <=g.vexnum; i++)
        {
            if(!flag[i]){
                if(p==-1)
                    p=i;
                else
                {
                    //找到最短的那个
                    p=dist[i]<dist[p]?i:p;
                }
            }
        }
        flag[p]=true;
        //输出路径
        //TODO

        //更新dist
        for (int i = 2; i <=g.vexnum; i++)
        {
            //如果访问
            if(flag[i]||g.edges[p][i]==INF)
                continue;
            int temp=dist[p]+g.edges[p][i];
            if(temp<dist[i]){
                dist[i]=temp;
                prev[i]=p;
            }
        }        
    }    
}
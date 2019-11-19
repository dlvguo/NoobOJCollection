#include <iostream>
using namespace std;

//假设图采用邻接矩阵的方法
struct Graph
{
    int edges[][];
    int vervexnum,edgenum;
};
#define INF -2 //表示邻接表不存在
//采用二分图染色法 如果单前结点的邻接点未染色就染与自己颜色不一样的 若上色了且颜色一样则不是二分图 否则忽略
bool Judge(Graph g){
    //采用非递归法
    int visit*=new int [g.vervexnum+1];//下标从1-vervennum
    //从第一个顶点开始 染色只要1和-1 其余visit初始化为0
    visit[1]=1;
    //用栈存放要遍历节点 假设栈足够大
    int stack[],top=-1;
    stack[++top]=1;
    while (top!=-1)
    {
        int v=stack[top--];
        for (int i =1; i <=g.vervexnum; i++)
        {
            if(v!=i){
                if(visit[i]==visit[v])
                    return false;
                else if(visit[i]==0){
                    visit[i]=visit[v]*-1;
                    stack[++top]=i;
                }
            }
        }
    }
    return true;
}
#include <iostream>
#include <queue>
using namespace std;

//使用邻接表存储 要使各个连通则度必须为偶数且不能为0
#define NUM 100
//用图存储
typedef struct arcnode
{
    arcnode *next;
    int v; //
} *Arcnode;

//边界点
typedef struct Vnode
{
    int vinfo; //节点信息
    Arcnode first;
} AdjList[NUM];

//邻接表
typedef struct graph
{
    AdjList adjver; //顶点
    int vertexnum, adjnum;
} Graph;

bool visit[NUM]; //代表访问节点

void dfs(Graph g, int v)
{
    visit[v] = true;
    Arcnode p = g.adjver[v].first;
    while (p)
    {
        if (!visit[p->next])
        {
            dfs(g, p->next);
        }
        p = p->next;
    }
}

bool Judge(Graph g){
    //先计算每一条边的度 若=0或奇数则出错
    for (int i = 0; i < g.vertexnum; i++)
    {
        int dgree=0;
        Arcnode p=g.adjver[i].first;
        while (p)
        {
            dgree++;
            p=p->next;
        }
        if(dgree==0||dgree%2)
            return false;
    }
    dfs(g,0);
    return true;
}
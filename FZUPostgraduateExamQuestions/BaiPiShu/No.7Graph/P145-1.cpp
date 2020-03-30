#include <iostream>
#include<queue>
using namespace std;

enum color
{
    red,
    green,
    yellow,
    black
};
//国家
struct nation
{
    color c;
    char *name;
};
#define NUM 100
//用图存储
typedef struct graph
{
    int edges[NUM][NUM];
    nation v[NUM];
    int nationnum, edgenum;
} Graph;
//使用BFS搜索图上色
void Coloring(Graph G)
{
    bool *visit = new bool[G.nationnum];
    for (int i = 0; i < G.nationnum; i++)
    {
        visit[i]=false;
    }
    queue<int> q;
    //给初始化节点上色然后BFS
    q.push(0);
    int colors=1;
    visit[0]=true;
    G.v[0].c=(color)0;
    while (!q.empty())
    {
        int v=q.front();
        q.pop();
        for (int i = 0; i < G.nationnum; i++)
        {
            if(G.edges[v][i]&&visit[i]){
                visit[i]=true;
                G.v[i].c=(color)colors;
                q.push(i);
            }
        }
        //0-3颜色变换
        colors=colors==3?0:colors+1;
    }    
}

int main()
{
    
}
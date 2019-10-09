#include <iostream>
#include<queue>
#include "../../Headers/graph.h"
using namespace std;

//使用邻接矩阵存放元素
//使用BFS搜索图上色
void BFS(MGraph G)
{
    bool *visit = new bool[G.vertexnum];
    for (int i = 0; i < G.vertexnum; i++)
    {
        visit[i]=false;
    }
    queue<int> q;
    //给初始化节点上色然后BFS
    q.push(0);
    visit[0]=true;
    cout<<G.vertexs[0];
    while (!q.empty())
    {
        int v=q.front();
        q.pop();
        for (int i = 0; i < G.vertexnum; i++)
        {
            if(G.edges[v][i]&&visit[i]){
                visit[i]=true;
                q.push(i);
                cout<<G.vertexs[i];
            }
        }
    }    
}

int main()
{
    
}
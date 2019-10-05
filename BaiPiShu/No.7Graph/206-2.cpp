#include <iostream>
#include "../../Headers/graph.h"
using namespace std;

bool visit[MaxVertex];

//如果成一课树 必须满足连通+（n-1）条边
bool IsUnion(ALGraph g)
{
    for (int i = 0; i < g.vertexnum; i++)
    {
        visit[i] = false;
    }
    //判断
    dfs(g, 0);
    if(g.vertexnum-1!=g.arcnum)
        return false;
    for (int i = 0; i < g.vertexnum; i++)
    {
        if (visit[i] == false)
            return false;
    }
    
    return true;
}

void dfs(ALGraph g, int v)
{
    visit[v]=false;
    for(int w=FirstNeighbor(g,v);w>=0;w=NextNeighbor(g,v,w)){
        if(!visit[w]){
            dfs(g,w);
        }
    }
}
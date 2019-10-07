#include <iostream>
#include "../../Headers/graph.h"
#include <queue>
using namespace std;

//DFS查看某个路径
bool visit[MaxVertex];
bool finddfs(MGraph g, int i, int j);
void DfsSearch(MGraph g, int i, int j)
{
    for (int i = 0; i < MaxVertex; i++)
        visit[i] = false;
    bool exit = finddfs(g, i, j);
}

bool finddfs(MGraph g, int i, int j)
{
    //先判断如果有的话
    if (g.edges[i][j])
        return true;
    if (visit[i])
        return false;
    for (int t = 0; t < g.vertexnum; t++)
    {
        if (!visit[t] && g.edges[i][t])
        {
            visit[t] = false;
            //下面一个节点看看有没有找到
            if (finddfs(g, t, j))
                return true;
        }
    }
    return false;
}

bool bfssearch(MGraph g, int i, int j)
{
    bool *visit = new bool[g.vertexnum];
    for (int k = 0; k < g.vertexnum; k++)
    {
        visit[k] = false;
    }

    queue<int> graphqueue;
    graphqueue.push(i);
    while (!graphqueue.empty())
    {
        //层次遍历
        int vertex = graphqueue.front();
        if(g.edges[vertex][j])
            return true;
        graphqueue.pop();
        for (int k = 0; k < g.vertexnum; k++)
        {
            if(visit[k]==false&&g.edges[vertex][k]){
                graphqueue.push(k);
                visit[k]=true;
            }
        }
    }
    return false;
}

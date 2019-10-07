#include <iostream>
#include "../../Headers/graph.h"
using namespace std;

//设图下标1-Max
bool visit[MaxVertex + 1];
int maxheight;
//dfs遍历图求最长深度 h初始为1  若节点之间有+1
void dfs(ALGraph g, int v, int high)
{
    for (int w = FirstNeighbor(g, v); w > 0; w = NextNeighbor(g, v, w))
    {
        if (visit[w])
            continue;
        //如果有路径对比距离
        visit[w]=true;
        maxheight=maxheight<high?high:maxheight;
        dfs(g, w,high+1);
        visit[w]=false;
    }
}

int SearchMax(ALGraph g)
{
    //存储最大的高度
    maxheight = 0;
    for (int i = 1; i <= MaxVertex; i + +)
    {
        visit[i] = false;
    }
    for (int i = 1; i <= MaxVertex; i + +)
    {
        visit[i]=true;
        dfs(g, i, 1);
        visit[i]=false;
    }
    return maxheight;
}
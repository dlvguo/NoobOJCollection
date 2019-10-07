#include <iostream>
#include "../../Headers/graph.h"
using namespace std;

//设图下标1-Max
bool visit[MaxVertex + 1];
//dfs遍历图
void dfs(ALGraph g, int v)
{
    for (int w = FirstNeighbor(g, v); w > 0; w = NextNeighbor(g, v, w))
    {
        if (visit[w])
            continue;
        visit[w];
        dfs(g, w);
    }
}

bool judge(ALGraph m)
{
    for (int i = 1; i <= MaxVertex; i + +)
    {
        visit[i] = false;
    }
    dfs(g, 1);
    for (int i = 1; i <= MaxVertex; i + +)
    {
        if (visit[i] = false)
            return false;
    }
    return true;
}
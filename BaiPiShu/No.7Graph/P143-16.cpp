#include <iostream>
#include "../../Headers/graph.h"
using namespace std;

//设图下标1-Max
bool visit[MaxVertex + 1];
void dfs(ALGraph g, int v)
{
    visit[v] = true;

    for (int w = FirstNeighbor(g, v); w > 0; w = NextNeighbor(g, v, w))
    {
        if (visit[w])
            continue;
        dfs(g, w);
    }
}

void DfsSearch(ALGraph g)
{
    for (int i = 1; i <= MaxVertex; i++)
    {
        visit[i] = false;
    }
    dfs(g, 1);
}
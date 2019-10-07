#include <iostream>
#include "../../Headers/graph.h"
using namespace std;

//??????
bool visit[MaxVertex + 1];
//???????????
int path[MaxVertex + 1], pathindex;

void deleteadj(MGraph g)
{
    int max = -1, v1, v2;
    for (int i = 1; i < pathindex; i++)
    {
        int tv1 = path[i - 1], tv2 = path[i];
        if (max < g.edges[tv1][tv2])
        {
            max = g.edges[tv1][tv2];
            v1 = tv1;
            v2 = tv2;
        }
    }
    g.edges[v1][v2] = 0;
    g.edges[v2][v1] = 0;
}

void dfs(ALGraph g, int v)
{
    visit[v] = true;
    for (int w = FirstNeighbor(g, v); w > 0; w = NextNeighbor(g, v, w))
    {
        //????path?
        path[pathindex++] = w;
        //??????
        if (visit[w])
        {
            deleteadj(g);
        }
        //???????
        else
        {
            dfs(g, w);
        }
        //??
        pathindex--;
    }
}

void DfsSearch(ALGraph g)
{
    for (int i = 1; i <= MaxVertex; i++)
    {
        visit[i] = false;
    }
    pathindex = 0;
    dfs(g, 1);
}
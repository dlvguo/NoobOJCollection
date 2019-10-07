#include <iostream>
#include "../../Headers/graph.h"
using namespace std;

bool visit[MaxVertex];
//用于存储路径
int path[MaxVertex];
int pathindex;

void searchallpath(ALGraph g, int i, int j)
{
    for (int i = 0; i < g.vertexnum; i++)
    {
        visit[i] = false;
    }
    pathindex = 0;
    dfs(g, i, j);
}

void dfs(ALGraph g, int i, int j)
{
    for (int w = FirstNeighbor(g, i); w >= 0; w = NextNeighbor(g, v, w))
    {
        if (w == j)
        {
            for (int i = 0; i < pathindex; i++)
            {
                cout << path[i];
            }
            cout << w<<endl;
        }
        //未访问过w 回溯
        else if (!visit[w])
        {
            path[pathindex++] = w;
            visit[w] = true;
            dfs(g, w, j);
            visit[w] = false;
            pathindex--;
        }
    }
}

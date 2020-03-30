#include <iostream>
#include "../../Headers/graph.h"
#include <queue>
using namespace std;

int FisrstEdge(int i);      //返回顶点i的第一条边对应的顶点
int NextEdge(int i, int j); //返回顶点i对应的j顶点的下一个顶点

bool Bfs(MGraph g, int i, int j)
{
    //使用邻接矩阵
    queue<int> vq;
    int *visit = new int[g.vertexnum + 1]; //表示1-vnum中是否被访问
    vq.push(i);
    while (!vq.empty())
    {
        int v = vq.front();
        vq.push();
        for (int k = FisrstEdge(i); k; k = NextEdge(i, k))
        {
            if (visit[k])
                continue;
            if (k == j)
                return true;
            visit[k]=true;
            vq.push(k);
        }
    }
    return false;
}

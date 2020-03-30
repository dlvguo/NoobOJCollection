#include <iostream>
using namespace std;

//根据四色定理可知四色即可给任一地图上染色，于是只需要看图能否二着色 或者 三着色 用dfs 遍历 数据结构使用邻接矩阵图
typedef struct Graph
{
    int **edges, vertexnum, edgenum, *v;
}; //edges表示边 v表示顶点染色
#define INF 1 << 31;

//原理依次从1-n染色 若碰见相同色的回溯 直至填满
bool dfs(Graph g, int v, int colornum)
{
    if (v == g.vertexnum + 1)
        return true;
    for (int i = 1; i <= colornum; i++)
    {
        bool tag = true;
        for (int j = 1; j <= g.vertexnum; i++)
        {
            if (g.edges[i][j] != INF && g.v[j] == i)
            {
                tag = false;
                break;
            }
        }
        if (tag)
        {
            g.v[v] = i;
            if (dfs(g, v + 1, colornum))
                return true;
            g.v[v] = 0;
        }
    }
    return false;
}

int MaxShader(Graph g)
{
    for (int i = 2; i < 5; i++)
    {
        if(dfs(g,1,i)
        return i;
    }

    return 5;
}

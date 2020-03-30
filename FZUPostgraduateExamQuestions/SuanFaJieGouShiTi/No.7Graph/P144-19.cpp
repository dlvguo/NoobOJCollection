#include <iostream>
#include "../../Headers/graph.h"
#include <queue>
using namespace std;

int FisrstEdge(int i);      //返回顶点i的第一条边对应的顶点
int NextEdge(int i, int j); //返回顶点i对应的j顶点的下一个顶点

//使用dfs 从每个顶点分别遍历
//其中 path[i][j]表示i到j点有路径 做备忘录算法剪枝
//v表示需要找根的节点
int path[][];
void dfs(int v, int i, MGraph g)
{
    for (int j = FisrstEdge(i); j; j = NextEdge(i, j))
    {
        //说明路径存在 则j点如果能连通的也将为1
        if (path[i][j])
        {
            for (int k = 1; k <= g.vertexnum; i++)
            {
                if (path[j][k])
                    path[i][k] = 1;
            }
        }
        else
        {
            path[i][j] = 1;
            dfs(v, j, g);
        }
    }
}

void SearchRoot(MGraph g)
{
    for (int i = 1; i <= g.vertexnum; i++)
    {
        dfs(i, i, g);
        //看看是否连通
        bool isRoot = true;
        for (int j = 1; j <= g.vertexnum; j++)
        {
            if (i != j && path[i][j] == 0)
            {
                isRoot = false;
                break;
            }
        }
        if (isRoot)
            cout << i << endl;
    }
}
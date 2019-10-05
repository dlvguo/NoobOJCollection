#include <iostream>
#include "../../Headers/graph.h"
#include <stack>
using namespace std;

//参考中序
void dfs(MGraph g)
{
    bool *visit = new bool[g.vertexnum];
    for (int i = 0; i < g.vertexnum; i++)
        visit[i] = false;
    stack<int> vertexstack;
    for (int i = 0; i < g.vertexnum; i++)
    {
        if (visit[i])
            continue;
        //入栈
        visit[i] = true;
        vertexstack.push(i);
        while (!vertexstack.empty())
        {
            int nowvertex = vertexstack.top();
            //看看当前节点是否还有指向  如果没有说明该节点访问完成 退栈
            bool isfind = false;
            //寻找第一个未被访问
            for (int j = 0; j < g.vertexnum; j++)
            {
                if (g.edgenum[nowvertex][j] && visit[j] == false)
                {                    
                    visit[j] = true;
                    vertexstack.push(i);
                    break;
                }
            }
            if (!isfind)
            {
                vertexstack.pop();
            }
        }
    }
}
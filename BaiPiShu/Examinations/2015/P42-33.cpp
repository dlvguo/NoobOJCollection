#include <iostream>
#include <cstring>
using namespace std;
typedef struct Graph
{
    //使用邻接矩阵的方法
    int vertexnum, edgenum;
    int edges[][];
};

int First(Grapgh g, int i);      //预留接口返回节点i相邻的第一个节点
int Next(Graph g, int i, int j); //返回节点i的相邻节点j的下一个与i相邻节点 不存在返回0

int visit[]; //表示每个节点被访问的情况
//用dfs深度遍历 若找到v-j的路径输出 回溯 直到找到所有的连通图
void dfs(Graph g, int i)
{
    visit[i] = 1;
    for (int w = First(g, i); w; w = Next(g, i, w))
    {
        if (!visit[w])
        {
            dfs(w);
        }
    }
}

void Search(Graph g, int v, int w)
{
    //从第一个顶点开始
    for (int i = 1; i <= g.vertexnum; i++)
    {
        //每次都初始化visit为0
        memset(a, 0, sizeof(a));
        dfs(i);
        if (visit[v] && visit[v] == visit[w])
        {
            for (int j = 1; j <= g.vertexnum; j++)
            {
                if (visit[j])
                    cout << j; //输出节点图
            }
        }
    }
}

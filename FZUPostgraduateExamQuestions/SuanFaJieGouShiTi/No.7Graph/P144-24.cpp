#include <iostream>
#include "../../Headers/graph.h"
#include <queue>
using namespace std;

int FirstAdj(int i);       //返回顶点i的第一条边对应的顶点
int NextAdj(int i, int j); //返回顶点i对应的j顶点的下一个顶点
int nodes(MGraph g);       //返回顶点数

int visit[]; //表示访问过的节点 若从i开始以及与i连通的节点的visit值都为i 表明一个集合 后面输出就可用来
void bfs(int v, MGraph g)
{
    queue<int> vq;
    visit[v] = v;
    vq.push(v);
    while (vq.empty() == false)
    {
        int p = vq.front();
        vq.pop();
        for (int w = FirstAdj(p); w; w = NextAdj(p, w))
        {
            if (visit[w] == 0)
            {
                visit[w] = v;
                vq.push(w);
            }
        }
    }
    int count = 0; //用于判断是不是第一个输出的
    for (int i = 1; i <= nodes(g); i++)
    {
        if (visit[i] == v)
        {
            if (count == 0)
                cout << "(" << i;
            else
            {
                cout << "," << i;
            }
        }
    }
    cout << ") ";
}

void Cout(MGraph g)
{
    for (int i = 1; i <= nodes(g); i++)
    {
        if (visit[i] == 0)
            bfs(i, g);
    }
}

int main()
{
}
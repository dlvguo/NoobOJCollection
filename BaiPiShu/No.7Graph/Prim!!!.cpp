#include <iostream>
#include "../../Headers/graph.h"
using namespace std;

//Prim 算法 取一个与顶点集最断的路径相连 直至生成最小数
#define MAXVALUE 999;
int Prim(MGraph g)
{
    int weight = 0;              //权值
    int *v = new int[g.vertexs]; //点集
    //表示该点与点集最近的点
    int *cloest = new int[g.vertexs];
    //表示该点与点集最近的点权值
    int *lowest = new int[g.vertexs];
    v[0] = true; //以0点开始遍历
    //初始化
    cloest[0] = lowest = 0;
    for (int i = 1; i < g.vertexs; i++)
    {
        v[i] = false;
        cloest[i] = 0;
        lowest[i] = g.edges[i][0];
    }
    int num = g.vertexs - 1;

    //执行n-1次
    while (num--)
    {
        int minvalue = MAXVALUE;
        int index = -1;
        for (int i = 0; i < g.vertexs; i++)
        {
            if (!v[i] && lowest[i] < minvalue)
            {
                minvalue = lowest[i];
                index = cloest[i];
            }
        }
        //加入点集
        weight += minvalue;
        v[index] = 1;
        //更新lowest
        for (int i = 0; i < g.vertexs; i++)
        {
            if (lowest[i] > g.edges[i][index])
            {
                lowest[i] = g.edges[i][index];
                cloest[i] = index;
            }
        }
    }
}

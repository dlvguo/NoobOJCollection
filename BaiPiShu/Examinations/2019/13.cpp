#include <iostream>
using namespace std;
//此题为最小生成树问题 使用Prim算法 岛屿之间用图数据结构
typedef struct Graph
{
    int vnum, edgenum, edges[][];
};
#define INF 77
int FigureMinCost(Graph g)
{
    //设成节点1开始做最小生成树
    int sum = 0;
    //cloest表示各点到已存入节点集合最近的点 若已经属于集合置为0 初始化为1
    //lowest表示各点到已存入节点集合的最短距离
    int *cloest = new int[g.vnum + 1];
    cloest[1] = 0;
    int *lowest = new int[g.vnum + 1];
    lowest = 0;
    for (int i = 2; i <= g.vnum; i++)
    {
        cloest[i] = 1;
        lowest[i] = g.edges[i][1];
    }
    for (int i = 1; i < g.vnum; i++) //每次找出一条边 n-1次即可
    {
        int min = INF, index; //INF表示无穷大
        for (int i = 1; i <= g.vnum; i++)
        {
            if (lowest[i] == 0 || min < lowest[i])
                continue;
            min = lowest[i];
            index = i;
        }
        sum+=min;//选出点之后
        lowest[index]=0;
        //调整cloest和lowest
        for (int i =1; i <=g.vnum; i++)
        {
            if(lowest[i]!=0&&lowest[i]>g.edges[i][index]){
                lowest[i]=g.edges[i][index];
                cloest[i]=index;
            }
        }
    }
    return sum;
}
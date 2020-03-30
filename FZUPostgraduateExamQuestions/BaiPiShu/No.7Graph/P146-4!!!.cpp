#include <iostream>
#include <queue>
using namespace std;

#define NUM 100
//用图存储
typedef struct graph
{
    int edges[NUM][NUM];
    int v[NUM];
    int vnum, edgenum;
} Graph;

//做法使用 Floyd 求出各个点之间最短距离，然后选出各个点之间最长的，再从最长之间选定位置即选定点
void Search(Graph g)
{
    for (int i = 0; i < g.vnum; i++)
    {
        for (int j = 0; j < g.vnum; j++)
        {
            for (int k = 0; k < g.vnum; k++)
            {
                if (g.edges[j][k] > g.edges[j][i] + g.edges[i][k])
                {
                    g.[j][k] = g.edges[j][i] + g.edges[i][k];
                }
            }
        }
    }
    //存放各个点中最长距离
    int dist[];
    for (int i = 0; i < g.vnum; i++)
    {
        int max = -1;
        for (int j = 0; j < g.vnum; j++)
        {
            if (max < g.edges[i][j])
                max = g.edges[i][j];
        }
        dist[i] = max;
    }
    //找出距离最短的
    int min = dist[0], index = 0;
    for (int i = 1; i < g.vnum; i++)
    {
        if (min > dist[i])
        {
            min = dist[i];
            index=i;
        }
    }
    cout<<"医院建立位置:"<<index<<"距离："<<min<<endl;
}

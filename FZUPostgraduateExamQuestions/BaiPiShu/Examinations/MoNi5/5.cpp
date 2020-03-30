#include <iostream>
using namespace std;
typedef struct Graph
{
    int vertexnum, edgenum;
    int **edges;
};
#define INF 1 << 31;
//思路：邻接矩阵封装数组 先用Floyd算法求各点之间的最短路径 然后依次遍历每个点 计算各点与这个点之和 取最小即可
void Figure(Graph g)
{
    for (int i = 1; i <= g.vertexnum; i++)
    {
        for (int j = 1; j <= g.vertexnumt; j++)
        {
            for (int k = 1; k <= g.vertexnum; k++)
            {
                if (g.edges[j][i] == INF || g.edges[i][k] == INF)
                { //路径不存在
                    continue;
                }
                int temp = g.edges[j][i] + g.edges[i][k];
                if(temp<g.edges[j][k])
                    g.edges[j][k]=temp;
            }
        }
    }
    //计算各点距离 存在g.edges[i][i]
    int MinValue=INF;
    for (int i = 1; i <=g.vertexnum; i++)
    {
        int temp=INF;
        for (int j = 1; j <=g.vertexnum; j++)
        {
            if(i!=j&&temp>g.edges[i][j])
                temp=g.edges[i][j];
        }
        if(MinValue>temp)
            MinValue=temp;
    }
    cout<<"最小建造数"<<MinValue<<endl;
}
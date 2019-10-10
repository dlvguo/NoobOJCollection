#include <iostream>
using namespace std;

#define NUM 100
//用图存储
typedef struct graph
{
    int edges[NUM][NUM];
    int v[NUM];
    int vnum, edgenum;
} Graph;

//首先用邻接矩阵作图 v[i][j]=1表示俩个国家相邻,v[i][j]=0表示不相邻
void Coloring(Graph G)
{
    int area = 1;     //代表当前染色数量 给第一个点染色 颜色为1 国家序号为0——NUM-1
    int nowcolor = 1; //当前颜色最大为4
    //第一个地方染色为1 如果当前区域染色不冲突则上色后将顶点入栈，否则出栈进行再次染色
    G.v[0] = 1;
    while (area < G.vnum)
    {
        while (nowcolor <= 4 && area < G.vnum)
        {
            int k = 1;
            //判断是否重色
            while (k < area && G.edges[area][k] * G.v[k] != nowcolor)
            {
                k++;
            }
            if (k == area)
            {
                //说明没有重复则
                G.v[area] = nowcolor;
                area++;
                nowcolor = 1;
            }
            else
            {
                nowcolor++;
            }
        }
        //回溯到上一个位置 换一个颜色继续染
        if (nowcolor > 4)
        {
            area--;
            nowcolor = G.v[area] + 1;
        }
    }
}

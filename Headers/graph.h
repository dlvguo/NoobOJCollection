#include <iostream>
using namespace std;

#define MaxVertex 100

#pragma region 邻接矩阵

typedef char vertextype ;
typedef int edgetype;
typedef struct mgraph
{
    int vertexnum, edgenum;
    //顶点集合
    vertextype  vertexs[MaxVertex];
    //边集合
    edgetype edges[MaxVertex][MaxVertex];
} MGraph;

#pragma endregion

#pragma region 邻接矩阵
typedef struct arcnode{
    int adjvex;
    arcnode *next;
}*ArcNode;

typedef struct VNode{
    vertextype data;
    ArcNode first;
}AdjList[MaxVertex];

typedef struct  algraph
{
    AdjList vertices;
    int vertexnum,arcnum;
}ALGraph;

//抽象结构
//初始化
void GraphInit(int n,ALGraph &g);
//判断边是否存在
bool GraphExits(int i,int j,ALGraph g);
//返回边数
int GraphEdges(ALGraph g);
//返回顶点数
int GraphVertex(ALGraph g);
//在图中加入边
void GraphAdd(int i,int j,ALGraph g);
//在途中删除边
void GraphDelete(int i,int j,ALGraph g);

//寻找图中某边的第一个点
int FirstNeighbor(ALGraph g,int v);

//寻找图中某点边的下一个点
int NextNeighbor(ALGraph g,int v,int w);

#pragma endregion
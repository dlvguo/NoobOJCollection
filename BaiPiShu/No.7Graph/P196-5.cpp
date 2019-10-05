#include<iostream>
#include"../../Headers/graph.h"
using namespace std;

ALGraph MGraphToALGraph(MGraph m){
    ALGraph algraph;
    //初始化
    GraphInit(m.vertexnum,algraph);
    algraph.vertexnum=m.vertexnum;
    algraph.arcnum=m.edgenum;
    for (int i = 0; i < m.vertexnum; i++)
    {
        for (int j = 0; j < m.vertexnum; j++)
        {
            if(m.edges[i][j]!=0){
                ArcNode node=new arcnode;
                node->adjvex=j;
                node->next= algraph.vertices[i].first;
                algraph.vertices[i].first=node;
            }
        }
    }
    return algraph;
}
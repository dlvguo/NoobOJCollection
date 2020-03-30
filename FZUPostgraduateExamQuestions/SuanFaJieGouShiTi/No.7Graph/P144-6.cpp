#include<iostream>
#include"../../Headers/graph.h"
using namespace std;

int FigureDegree(MGraph g){
    int count=0;
    for (int i = 1; i <=g.vertexnum; i++)
    {
        for (int j = 1; i <=g.vertexnum; i++)
        {
            if(g.edges[i][j])
                count++;
        }
    }
    return count;
}

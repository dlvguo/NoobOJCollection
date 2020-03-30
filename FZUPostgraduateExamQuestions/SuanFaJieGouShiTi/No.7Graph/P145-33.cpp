#include <iostream>
#include "../../Headers/graph.h"
#include <queue>
using namespace std;

#define Inf int.Maxvalue
void Flyod(MGraph g)
{
    for (int i = 1; i <= g.vertexnum; i++)
        for (int j = 1; j <= g.vertexnum; j++)
            for (int k = 1; k<=g.vertexnum; k++)
            {
                int temp=g.edges[j][i]+g.edges[i][k];
                if(temp<g[j][k])
                    g.edges[j][k]=temp;
            }
}
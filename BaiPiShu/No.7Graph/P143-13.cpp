#include<iostream>
#include"../../Headers/graph.h"
#include<stack>
using namespace std;

void D_visit(ALGraph m){
    bool visit[MaxVertex+1];
    for (int i = 1; i <= MaxVertex; i++)
    {
        visit[i]=false;
    }
    visit[1]=true;
    stack<int> vstack;
    vstack.push(1);
    //从点1开始遍历
    while (!vstack.empty())
    {
        int v=vstack.top();
        vstack.pop();
        ArcNode arcnode=m.vertices[v].first;
        
        while (arcnode)
        {
            if(visit[arcnode->adjvex])
                continue;
            visit[arcnode->adjvex]=true;
            vstack.push(arcnode->adjvex);
            arcnode=arcnode->next;
        }
    }   
}
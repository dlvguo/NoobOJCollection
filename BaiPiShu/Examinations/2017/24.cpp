#include<iostream>
#include<queue>
using namespace std;
typedef struct Node{
    int x,y,step;
};
bool visit[][];
int div[4][2]={0,1,0,-1,1,0,-1,1};
int FindMin(char map[][],int ax,int ay,int m,int n){
    Node p;
    p.x=ax;
    p.y=ay;
    visit[ax][ay]=true;
    queue<Node> q;
    q.push(p);
    while (!q.empty())
    {
        p=q.front();q.push();
        for (int i = 0; i<4; i++)
        {
            int x1=p.x+div[i][0],y1=p.x+div[i][1];
            if(x1<1||y1<1||x1>m||y1>n||visit[x1][y1])
                continue;
            visit[x1][y1]=true;
            if(map[x1][y1]=='b')
                return p.step+1;
            else if(map[x1][y1]!='*'){
                Node n;n.x=x1;n.y=y1;n.step=p.step+1;
                q.push(n);
            }
        }
        
    }
    return -1;
}
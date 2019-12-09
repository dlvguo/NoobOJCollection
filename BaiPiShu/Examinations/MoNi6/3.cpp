#include<iostream>
#include<queue>
using namespace std;

//思路BFS 从a点出发遍历直至到点b
int div[4][2]={0,1,0,-1,1,0,-1,0};//表示只允许直接布线四个方向
#define M 555
#define N 666
//结构体用于存放当前坐标点的位置和已走布线
typedef struct Pos{
    int x,y,setp;
};

int SearchMin(int map[],int xa,int ya,int xb,int yb){//表示图和xy的目标点 地图中值为1表示封锁为0表示ok
    queue<Pos> queue;
    Pos p;
    p.x=xa;p.y=ya;p.setp=0;
    queue.push(p);
    int visit[M+1][N+1]={0};
    while (!queue.empty())
    {
        p=queue.front();
        queue.pop();
        for (int i = 0; i<4; i++)
        {
            int x=p.x+div[i][0],y=p.y+div[i][1];
            if(x==xb&&y==yb){
                return p.setp+1;
            }
            if(x<1||y<1||x>M||y>n||visit[x][y])
                continue;
            visit[x][y]=1;
            if(map[x][y]==1){
                continue;
            }
            else {
                Pos temp;
                temp.x=x;
                temp.y=y;
                temp.setp=p.setp+1;
                queue.push(temp);
            }
        }
    }    
    return -1;
}
#include<iostream>
using namespace std;
//即dfs遍历最大连接块 用二维数组存放这个map 值为1 表示上色 0表示无色
//思路：用visit存放遍历过的点 从第一个点开始遍历 发现这个点未遍历进入dfs遍历与这个点相连的所有点 最后几次dfs就是最大可消次数
#define M 55
#define N 55
int visit[M+1][N+1];
int div[4][2]={0,1,0,-1,1,0,-1,0};//表示遍历的四个方向

void dfs(int map[][N+1],int x,int y){
    for (int i = 0; i <4; i++)
    {
        int _x=x+div[i][0],_y=x+div[i][1];
        if(_x<1||_y<1||x>M||y>M||visit[_x][_y])
            continue;
        visit[_x][_y]=1;
        if(map[_x][_y]==1){
            dfs(map,_x,_y);
        }
    }
}

int FigureMaxDelete(int map[][N+1]){
    int sum=0;
    for (int i = 1; i <=M; i++)
    {
        for (int j=1;j<=N; j++)
        {
            if(visit[i][j])
                continue;
            visit[i][j]=1;
            if(map[i][j]==1){
                dfs(map,i,j);
                sum++;
            }
        }
        
    }
    return sum;   
}
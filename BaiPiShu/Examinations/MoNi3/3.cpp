#include<iostream>
using namespace std;

//DFS暴力求解法 尝试每种方法 若找到全覆盖则返回
//表示四个图像
#define K 999
int block[4][6]={{0,0,0,1,1,0},{0,0,0,1,1,1},{0,0,1,0,1,1},{0,0,0,1,1,1}};
int visit[K][k]；//表示访问过的节点 visit[i][i]=1 表示上的方块1 初始化为0 

bool Judge(){
    for (int i = 0; i <K; i++)
    {
        for (int j = 0; j < K; j++)
        {
            if(!visit[i][j])
                return false;
        }
        
    }
    return true;
}

bool dfs(int map[][],int x,int y){
    if(x>=K||y>=K||x<0||y<0||visit[x][y])
        return false;
    for (int i = 0; i <4; i++)
    {
        //先看看三个方块放的点会不会冲突用个tag打标记
        int x1=x+div[i][0],y1=y+div[i][1],x2=x+div[i][2],y2=y+div[i][3],x3=x+div[i][4],y3=div[i][5]+y;
        if(visit[x1][y1]||visit[x2][y2]||visit[x3][y3])
            continue;
        visit[x1][y1]=1;
        visit[x2][y2]=1;
        visit[x3][y3]=1;
        if(dfs(map,))

    }
    
}
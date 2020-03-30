#include<iostream>
using namespace std;
//骑士周游问题 暴力dfs
//思路采用回溯+dfs进行遍历 若骑士走了63步说明遍历了每一个点则返回true 并输出路线
int dist[10][2]={-2,1,-2,-1,2,1,2,-1,-1,2,1,2,-1,-2,1,-2};//表示马能够走的八个方向
#define M 8
#define N 8

int visit[M+1][N+1];//表示遍历过的节点 为方便数组下界为1-8

bool dfs(int x=1,int y=1,int step=0){
    if(step==63){
        cout<<x<<y<<endl;
        return true;
    }
    for (int i = 0; i <8; i++)
    {
        int x1=x+dist[i][0];
        int y1=y+dist[i][1];
        if(x1<1||y1<1||x1>8||y1>8||visit[x1][y1]) 
            continue;
        visit[x1][y1]=1;
        if(dfs(x1,y1,step+1)){
            cout<<x1<<y1;
            return true;
        }
        visit[x1][y1]=0;
    }
    return false;
}

int main(){
    
    for (int i =1; i <=8; i++)
    {
        for (int j = 1; j <=8; j++)
        {
            if(dfs(i,j,0))
            break;
        }
    }
}
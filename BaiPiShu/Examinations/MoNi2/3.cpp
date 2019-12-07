#include<iostream>
using namespace std;

//最简单的暴力法 若没有限制的话 之后算出sum
int minvalue=0;
int visit[60];//表示访问过的值
int N;
#define Inf 0x3f3f3f3f;
#define MAX 1<<31;//这个写法也帅
void Dfs(int v,int **map,int nowvalue,int sum=1){//v表示当前访问的节点 sum表示访问总数当总数==n说明全访问 做全排列
    if(sum==N){
        minvalue=nowvalue>minvalue?minvalue:nowvalue;
    }
    for (int i = 1; i <=N; i++)
    {
        if(visit[i]||map[v][i]==-1)
            continue;
        visit[i]=1;
        Dfs(i,map,nowvalue+map[v][i],sum+1);
        visit[i]=0;
    }
}

int main(){

}

//还有一种状态压缩 感觉是重点看的蒙 后续总结
//状态压缩dp[i][s]表示当前i到s所访问的最短路径 目标是1到s s表示所有点 s用二进制表示集合
//dp[j][S|1<<i]=minvalue(dp[i][S]+G[i][j]) j表示到集合 S|j即放入j点
//dp[i][S]=minvalue{dp(i,S^(1<<i))+G[i][j]}//表示i在j中  //注意二进制数已经下标问题 去掉下标异或就好了
//初始化 dp[i][1<<i]=0

typedef struct Graph{
    int edgenum,vertexnum,**edges;
};

int Min(Graph g){
    int **dp;//初始情况为0
    for (int s = 0; s < (1<<g.vertexnum); s++)//移动到n位置
    {
        for (int i = 0; i <g.vertexnum; i++)
        {
            if(1<<i&s){//如果i在集合中
                for (int j = 0; j <g.vertexnum; i++)
                {
                    if((!(1<<j)&s)&&g.edges[i][j]!=Inf){//这个是从i-j j不在集合
                        dp[j][s|1<<i]=min(dp[j][s],dp[i][s]+G[i][j]);
                    }
                }
            }
        }
        /* 另外种是 j已经在s里 从i-j 说明i也在
        for(int j=0;j<g.vertexnum;j++){
            if(1<<j&s){
                for(int i=0;i<g.vertexnum;i++){
                    if(1<<i&s&&g.edges[i][j]!=Inf){
                        dp[j][s]=min(dp[j][s],dp[i][j^(1<<i)]+g.edges[i][j])
                    }
                }
            }
        }
        */
    }
    return dp[1][g.vertexnum];      
}
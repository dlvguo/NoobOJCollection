#include<iostream>
#include<cstring>
using namespace std;

//用图存放各元素 用DFS暴力求解 每次从元素中一个顶点 vi
//然后从vi出发求最大权值的路径 即一趟可以修复最多的路 若此时还有未遍历的点 遍历剩下的点 此时可以算出vi要修复wi次
//之后从这里面选取最小的即可
typedef struct Graph{
    int edges[][],edgenum,vernum,v[];
};

int maxvalue=0,visit[];//maxvalue表示此趟最大value值 visit[]表示此趟的最大值
void dfs(Graph g,int v){//v表示访问的节点

}


void main(){
    Graph g;
    int m;
    g.vernum=m;g.edges=m+m-2;
    cin>>m;
    for (int i = 1; i <=m-1; i++)
    {
        int i,j,w;
        cin>>i>>j>>w;
        //这是一个有连接的地方
        g.edges[i][j]=w;
        g.edges[j][i]=w;
    }
     //每个点去遍历
    for (int i = 1; i <=g.vernum; i++)
    {
        memset(g.v,0,sizeof(g.v));//每次都置为0 当g.v[]不等于0表示此点完成 同时这个
        //每个顶点开头要多趟dfs 每一趟dfs都是寻找在点未遍历完的情况下 去搜索
        dfs(g,i);
        
    }
    
}
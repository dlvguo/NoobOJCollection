#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
int visit[5][5];
int add[4][2]={-1,0,0,1,0,-1,1,0},flag;
int mg[5][5];
struct node{
	int x;
	int y;
}father[6][6];
void bfs(int x=0,int y=0){
	int i,x1,x2;
	queue<node>q;
	node first,next;
	first.x=x;
	first.y=y;
	q.push(first);
	father[x][y].x=x;
	father[x][y].y=y;
	while(!q.empty()){
	  first=q.front();
	  q.pop();
	  if(first.x==4&&first.y==4)
	  return ;
	  for (i=0;i<4;i++){
	   next.x=first.x+add[i][0];
	   next.y=first.y+add[i][1];
	   if (next.x<0||next.x>4||next.y<0||next.y>4)
	   continue;
	   if (mg[next.x][next.y]==1)
	   continue;
	   if (visit[next.x][next.y])
	   continue;
	   visit[next.x][next.y]=1;
	   father[next.x][next.y].x=first.x;
	   father[next.x][next.y].y=first.y;
	   q.push(next);
	  }
	}
}

void dfs (int x,int y){
	if (!(father[x][y].x==0&&father[x][y].y==0))
	dfs(father[x][y].x,father[x][y].y);
	printf("(%d,%d)\n",father[x][y].x,father[x][y].y);
}
int main(){
	int i,j;
	for (i=0;i<5;i++)
	for (j=0;j<5;j++)
	cin>>mg[i][j];
	flag=0;
	memset(visit,0,sizeof(visit));
	bfs();
	dfs(4,4);
	printf("(4,4)\n");
}

#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

typedef struct point{
	int x;
	int y;
	int cont;
}P;
#define MAX 9
int yd[MAX][2]={-1,2,-1,-2,-2,1,-2,-1,1,2,1,-2,2,1,2,-1},visit[MAX][MAX];

int dfs(P head,P end){
	int i;
	P next,a;
	queue<P>look;
	look.push(head);
	memset(visit,0,sizeof(visit));
	visit[head.x][head.y]=1;
	while(!look.empty()){
		a=look.front();
		if(a.x==end.x&&a.y==end.y){
		return a.cont;}
		for(i=0;i<8;i++){
	  next.x=a.x+yd[i][0];
	  next.y=a.y+yd[i][1];
	  if(next.x<1||next.x>8||next.y<1||next.y>8)
	  continue;
	  if(visit[next.x][next.y])
	  continue;
	  next.cont=a.cont+1;
	  visit[next.x][next.y]=1;
	  look.push(next);
		}
		look.pop();}
	}

int main(){
  P start,end;
  char s1[2],s2[2];
  while(scanf("%s%s",s1,s2)!=EOF){
  start.x=s1[0]-96;
  start.y=s1[1]-'0';
  start.cont=0;
  end.x=s2[0]-96;
  end.y=s2[1]-'0';
  printf("To get from %s to %s takes %d knight moves.\n",s1,s2,dfs(start,end));}
  return 0;
} 

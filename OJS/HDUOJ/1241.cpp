#include<iostream>
#include<cstring>
using namespace std;
int visit[111][111];
char sy[105][105];
int n,m;
int zb[8][2]={1,1,1,0,1,-1,0,1,0,-1,-1,1,-1,0,-1,-1};
void dfs(int h,int l){
	int i,x,y;
	for (i=0;i<8;i++){
		x=l+zb[i][1];
		y=h+zb[i][0];
		if (x<0||x>=m||y<0||y>=n)
		continue;
		if(sy[y][x]=='*')
		continue; 
		if (visit[y][x])
		continue;
		if (sy[y][x]=='@'){
			visit[y][x]=1;
			dfs(y,x);
		}
	}
}
int main(){
	int i,j,sum;
	while (cin>>n>>m){
		sum=0;
		if (n==0&&m==0)
		break;
		for (i=0;i<n;i++)
		for (j=0;j<m;j++)
		cin>>sy[i][j];
		memset(visit,0,sizeof(visit));
		for (i=0;i<n;i++)
		for (j=0;j<m;j++){
			if (sy[i][j]=='*'||visit[i][j]==1)
			continue;
			visit[i][j]=1;
		  dfs(i,j);
		  sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
} 

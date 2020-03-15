#include<iostream>
#include<cstring>
using namespace std;

struct G{
	int begin;
	int end;
	int value;
	bool isFind=false;
};
G g[11111];
int n,m;
int isFind[100];

void findMin(){
	int	minvalue=0;

    isFind[1]=1;
	for(int i=1;i<=m;i++){
		int min=-1;
		int gindex;
		int index;
		for(int j=1;j<=n;j++){
			int b=g[j].begin;
			int e=g[j].end;
			if(!isFind[b]&&!isFind[e]||isFind[b]&&isFind[e]||g[j].isFind)			
				continue;
			if(min==-1||min>g[j].value){
				min=g[j].value;
				gindex=isFind[e]?b:e;
				index=j;
			}
		}
		if(min!=-1){
			minvalue+=min;
			isFind[gindex]=1;
			g[index].isFind=true;
		}
	}
		for(int k=1;k<=m;k++){
			if(!isFind[k]){
				cout<<"?\n";
				return;
			}
		}
			cout<<minvalue<<endl;
}

int main(){
	while(cin>>m>>n){
	    memset(isFind,0,sizeof(isFind));
		for(int i=1;i<=n;i++){
	    	int  b,e,v;
	    	cin>>b>>e>>v;
	    	g[i].begin=b;
	    	g[i].end=e;
	    	g[i].value=v;
	    	g[i].isFind=false;
		}
		findMin();
	}	
	return 0;
}

#include<iostream>
using namespace std;

int main(){
	int n;
	int num[7]={0,100,50,10,5,2,1};
	while(cin>>n){
		int count=0;
		int m;
		for(int i=0;i<n;i++){
			cin>>m;
			for(int j=1;j<7;j++){
				count+=m/num[j];				
				if(m%num[j]<=0)
				  break;
				m%=num[j];
			}
		}
		if(count)
		   cout<<count<<endl;
		else
		   cout<<"Impossible\n";
	}	
	return 0;
}

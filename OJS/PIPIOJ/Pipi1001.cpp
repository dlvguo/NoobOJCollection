#include<iostream>
using namespace std;

bool IsShui(int num){
	return num==(num/100)*(num/100)*(num/100)+(num%10)*(num%10)*(num%10)+(num/10%10)*(num/10%10)*(num/10%10);
}

int main(){
	
	int n,m;
	while(cin>>n>>m){
		int count=0;
		for(int i=n;i<=m;i++){
			if(IsShui(i)){
				if(count!=0)
				  cout<<' ';
				cout<<i;
				count++;
			}
		}
		if(count==0)
		  cout<<"no";
		cout<<endl;
	}
	
	
}

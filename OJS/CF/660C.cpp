#include<iostream>
using namespace std;
#define MAX 300050
int a[MAX];

main(){
	long long n,k,i,fc,start,end1=0,end2=0,max=0;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=1;i<=n;i++){
		for(start=i,fc=k;;start++){
			if (start>n)
			break;
			if(!a[start]&&fc!=0){
			fc--;continue;}
			if (!fc){
				if(!a[start]){
				break;}
			}
				}
		if (start-i>max){
			max=start-i;
			end1=i;
			end2=start-1;
		}
		}
	cout<<max<<endl;
	if(end1==1)
	cout<<1;
	else
	cout<<a[1];
	  for(i=2;i<=n;i++){
	  	if(i>=end1&&i<=end2)
	  	cout<<' '<<1;
	  	else
	  	cout<<' '<<a[i];
	  	
		}
	}

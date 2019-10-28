#include<iostream>
#include<cstring>
using namespace std;

int getType(char c){
	int n=(int)c;
	if(n>=65&&n<=90){
		return 1;
	}
	else if(n>=97&&n<=122){
		return 2;
	}
	else if(n>=48&&n<=57)
	    return 3;
	    return 4;
}

int main(){
	string str;
    int arr[5];
    string sc;
	while(cin>>str){
		memset(arr,0,sizeof(arr));
		if(str.length()<8){
			sc="NO";
		}
		else{
			for(int i=0;i<str.length();i++){
				int num=getType(str[i]);
				arr[num]=1;
			}
		}
		int count=0;
		for(int i=1;i<5;i++){
			if(arr[i]>0)
				count++;
		}
		sc=count>2?"YES":"NO";
		cout<<sc<<endl;
	}
}

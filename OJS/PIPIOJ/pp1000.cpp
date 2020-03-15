#include<iostream>
#include<cstring>
using namespace std;

int main(){
	char s[111];
	int count=0;
	while(scanf("%s",s)!=EOF){
		count++;
        int len=strlen(s);
        bool isHW=true;
        
        for(int i=0;i<len/2;i++){
        	if(s[i]!=s[len-1-i]){
        		isHW=false;
        		break;
			}
		}
        //string str=isHW?"yes":"no";
        if(isHW)
        cout<<"case"<<count<<"£ºyes"<<endl;
        else
        cout<<"case"<<count<<"£ºno"<<endl;

	}
	return 0;
} 

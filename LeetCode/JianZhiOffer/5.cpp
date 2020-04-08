#include<iostream>
#include<vector>
#include<deque>
#include<string>
using namespace std;

 string replaceSpace(string s) {
	 int len=s.length();
	 int spaceNum=0;
	 for(int i=0;i<len;i++){
		if(s[i]==' ')
			spaceNum++;
	 }
	string str="";
	int totalNum=spaceNum*2+len;
	str.resize(totalNum);
	totalNum--;
	for(int i=len-1;i>=0;i--){
		if(s[i]==' '){
			str[totalNum--]='0';			
			str[totalNum--]='2';
			str[totalNum--]='%';
		}
		else{
			str[totalNum--]=s[i];			
		}
	}
	return str;
 }

int main(){
	cout<<"FUCK";
	system("pause");
	int ab;
	vector<int> v;
}
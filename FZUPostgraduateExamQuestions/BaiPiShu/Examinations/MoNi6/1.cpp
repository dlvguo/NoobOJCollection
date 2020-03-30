#include<iostream>
#include<math.h>
using namespace std;
//情况采用回溯 f(n,n)表示拆分n个集合于是有
int f(int n,int m){
    if(m==1||n==m){
        return 1;
    }
    return f(n-1,m-1)+f(n-1,m)*m;
}

int main(){
    int n,ans=0;
    cin>>n;
    for (int i = 1; i <=n; i++)
    {
        ans+=f(n,i);
    }
    cout<<ans<<endl;
}
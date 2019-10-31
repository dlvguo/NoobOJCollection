#include<iostream>
using namespace std;

//最长递增序列 b[i]表示序列这个数最长的多少 有递推解Max{b[i-1]+a[i],a[i]}
int Max(int a,int b)
{
    return a>b?a:b;
}

//若有其他情况可自定义
int Figure(int a[],int len){
    int b[],max;
    max=b[1]=a[1];
    for(int i=2;i<=n;i++){
        b[i]=Max(b[i-1]+a[i],a[i]);
        max=Max(max,b[i]);
    }
    return max;
}
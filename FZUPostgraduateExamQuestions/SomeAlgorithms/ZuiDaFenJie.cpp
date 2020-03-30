#include <iostream>
using namespace std;

//在不超过m的情况下 n能分解几种情况
int f(int n, int m)
{
    //如果m或者n==1 只能1种情况
    if(n==1||m==1)
        return 1;
    if(n<m)
        return f(n,n);
    if(n==m){
        return 1+f(n,m-1);
    }
    //n>m的情况 就是分成带有m的一种
    return 1+f(n-m,m)+f(n,m-1);
}
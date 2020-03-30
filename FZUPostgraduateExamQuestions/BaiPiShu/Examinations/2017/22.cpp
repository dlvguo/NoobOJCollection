#include<iostream>
using namespace std;
//计算二进制问题 TMD 一个用常见方法Log2
int FigureOne(int n){
    int sum=0;
    while (n)
    {
        if(n%2)
            sum++;
        n/=2;
    }
    return sum;
}

//用10计算 每次看二进制的按位& 如果有就继续 跟上诉方法差不多都是/2
int FigureTwo(int n){
    int sum=0;
    while (n)
    {
        if(n&1)
            sum++;
        n>>1;
    }
}

//计算跟二进制个数有关
int FigureThree(int n){
    int sum=0;
    while (n)//与自己-1 & 当没有的时候就over
    {
        n&=(n-1);
        cout<<n;
        sum++;
    }
    
    return sum;
}
#define MAX_SIZE 100
//还有一个传说中O(1) 打表法
int FigureFour(int n){
    int v[16]={0,1,1,2};//}....
    if(n<=MAX_SIZE)
    return v[n];
    return -1;
}

int main(){
    int s=FigureThree(10);
    cout<<s;
}
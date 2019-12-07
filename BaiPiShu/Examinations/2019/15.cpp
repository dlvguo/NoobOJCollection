#include<iostream>
#include<math.h>
using namespace std;

//因为集合只有1-N,假设看成数组的话如a[1]=1表示数字1存在 a[2]=1表示数字2存在 故可用一个二进制表示
//因为一开始把n个数插入集合 则用2^n-1表示 可能数字大因此用pow函数
void PrintDeleteMin(int n,int m){
    long long N=pow(2,n)-1;
    //用一个变量表示m初始为1 每多一次则表示1<<m 这样就能确定m的数了,同时每次删除让让m取反与N取&操作
    int M=1;
    for (int i = 1; i <=m; i++)
    {
        N&=~M;//先删除目标最小数
        //将N取反 只要有1的就删除
        int count=1;
        int k=~N;
        while (k)
        {
            cout<<count;
            k>>1;
            count++;
        }
        1<<M;//之后M向左移更新删除目标数
    }
}
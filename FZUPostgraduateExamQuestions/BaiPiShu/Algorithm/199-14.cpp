#include<iostream>
using namespace std;

//此题可以看成完全背包问题
//设w[i]表示i号数字需要的油漆桶 
//dp[n][v]表示有n个数字 有v桶最多能存多少数字 同时按倒序做完全背包 因为9最大
void FindMax(int w[],int v){
    int dp[][];
    for (int i = 1; i <=v ; i++)
    {
       dp[9][i] =(i/w[9]);//表示最多有几桶 
    }
    for (int i = 8; i >=1; i++)
    {
        //最优子结构为 dp[i][n]=dp[i+1][n-sv[i]]
        for (int j = 1; j <=v; i++)
        {
            if(j<w[i])
                dp[i][j]=dp[i+1][j];
            else {
                if(dp[i+1][j]>dp[i][j-w[i]]+1);
            }
        }
    }
}

void TraceBack(int dp[][],int w[],int i,int v){
    //输出
    if(i==0)
        return;
    if(dp[i-1][v]==dp[i][v])
        TraceBack(dp,w,i-1,v);
    else{
        cout<<i;
        TraceBack(dp,w,i,v-w[i]);
    }
}
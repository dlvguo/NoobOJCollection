#include<iostream>
#include<math.h>
using namespace std;

//算法思路:使用状态压缩dp进行求解 dp[n]表示完成n个任务所需花费最短时间
//如n=3 表示有3个任务 111 则前一状态可以为011 101 011 故最优子结构为
//dp[n]={min{dp[n],dp[n^(1<<i)]+time[1i]+time[2i]}}

int FigureMintime(int t1[],int t2[],int n){
    //需要用n个二进制表示于是总数为2^n-1
    long long N=pow(2,n);
    int dp=new int[N];//初始值为0
    for (int i =1; i <N; i++)//遍历每个状态
    {
        for (int j = 0; j <n; j++)
        {
            if(i&&(1<<j)){//
                int temp=dp[i^(1<<j)];
                if(temp==0){//说明上个位置为初始化于是有
                    dp[i]=t1[j]+t2[j];
                    continue;
                }
                temp+=t1[j]+t2[j];
                if(dp[i]>temp){
                    dp[i]=temp;
                }
                
            }
        }
    }
    return dp[N];
}   

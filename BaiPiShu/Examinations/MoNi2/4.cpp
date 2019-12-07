#include<iostream>
using namespace std;

int min(int a,int b){
    return a>b?b:a;
}

//思路：使用动态规划求解 dp[1][n]表示1-n最小代价 dp[i][j]=min{dp[i][j],dp[i][k]+dp[k+1][j]+w[i,j]}//w[i][j]表示i-j中值
#define INF 0x3f3f3f3f;
void FigureMin(int w[],int n){//设数组下标为1-n 
    int dp[50][50]={0};
    int *sum=new int[n+1];//sum i表示1-i有多少石子
    //i=j的时候为INF INf为最大值于是有
    for (int i = 1; i <=n; i++)
    {
        dp[i][i]=INF;
        sum[i]=sum[i-1]+w[i];
    }
    for (int r= 2; r <=n; r++)
    {
        for (int left = 1; left <= n-r+1; i++)
        {
            int right=r+left-1;
            for (int mid = left+1; mid <right; i++)
            {
                int temp=sum[right]-sum[left-1];//下标提示1-n即可 否则sum计算有点问题
                dp[left][right]=min(dp[left][right],dp[left][mid]+dp[mid+1][right]+temp);
            }
        }
    }
    cout<<dp[1][n];
}
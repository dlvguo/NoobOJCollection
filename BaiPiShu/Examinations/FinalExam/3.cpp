#include <iostream>
using namespace std;

#define MAX 10
//使用动态规划：dp[i][j]表示从i-j房子偷的最大金额
//最优子结构为 dp[i][j]=dp[i][k-2]+w[k]+dp[K+2][j]
//其中若i>j=0
int FigureMax(int w[], int n)
{
    int dp[MAX][MAX] = {0}; //初始化为0
    //初始化 dp[i][i]为自身 于是有
    for (int i = 1; i <=n; i++)
    {
        dp[i][i]=w[i];
    }
    
    for (int r = 2; r <= n; r++)
    {
        for (int left = 1; left <= n - r + 1; left++)
        {
            int right = left + r - 1;
            for (int mid = left + 1; mid < right;mid++)
            {
                int temp = w[mid];
                if ((mid - 2) >= left)
                    temp += dp[left][mid - 2];
                if (mid + 2 <= right)
                    temp += dp[mid + 2][right];
                if(temp>dp[left][right])
                    dp[left][right]=temp;
            }
        }
    }
    return dp[1][n];
}

//FUCK 搞复杂了 dp[i]表示从1-i的最大值于是有解结构为dp[i]={dp[i-2]+dp[i],dp[i-1]}
int Account(int w[],int n){
    int *dp=new int[n+1];
    //初始化dp[i]=w[i]
    for(int i=1;i<=n;i++)
        dp[i]=w[i];
    for (int i = 2; i <=n; i++)
    {
        int temp=dp[i-2]+w[i];
        if(temp>dp[i-1])
            dp[i]=temp;
        else
        {
            dp[i]=dp[i-1];
        }
        
    }
    return dp[n];
}

int main(){
    int a[10]={0,3,2,1,5,1,1,100};
    cout<<FigureMax(a,4)<<endl;
    cout<<Account(a,4);
}


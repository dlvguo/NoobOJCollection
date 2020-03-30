#include <iostream>
using namespace std;
#define N 50
int max(int a,int b){
    return a>b?a:b;
}
//dp[i][j]表示i-j层最大值 于是有动态转移方程dp[i][j]=max{dp[i][k-1]+dp[k+1][j]+a[k]*a[i-1]*a[j+1],dp[i][j]}i<=k<=j
void OpenQiqiu(int a[], int n)
{
    int result[N][N] = {0};//注意遍历dp范围
    for (int r = 1; r <= n; r++)//本来是2 mid也是从left+1 但是这个是左右俩堆加起来 说明k左右边已经合在一起所以乘是left-1 right+1
    {
        for (int left = 1; left <= n - r + 1; left++)
        {
            int right = r + left - 1;
            for (int mid = left; mid <= right; mid++)
            {
                result[left][right]=max(result[left][right],result[left][mid-1]+result[mid+1][right]+a[left-1]*a[mid]*a[right+1]);
            }
        }
    }
    cout<<result[1][n]<<endl;
}
int main()
{
    int a[6] = {1, 3, 1, 5, 8, 1};
    OpenQiqiu(a, 4);
}

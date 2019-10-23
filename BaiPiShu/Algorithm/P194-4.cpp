#include <iostream>
#include<math.h>
using namespace std;
void MaxHe(int a[], int n)
{
    int *dp = new int[n + 1], max; //dp[i]表示当前数字的最大序列和 动态转移方程为 dp[i]=max{dp[i-1]+a[i],a[i]}
    max = dp[1] = a[1];
    for (int i = 2; i <= n; i++)
    {

        dp[i] = dp[i - 1] + a[i]> a[i]?dp[i-1]+a[i]:a[i];
        //判断下dp是否变化
        max = dp[i] > max ? dp[i] : max;
    }
    cout << max;
}

int main(){
    int a[6]={5,5,-2,10,3,-199};
    MaxHe(a,5);
}
#include<iostream>
using namespace std;

//常识可知当 因子越平均所乘积越大 故只要平均分即可
void Max(int n,int m){
    int *a=new int[m];
    //首先n/m 给每段都赋值 剩下的余数有多少就分多少每个1
    a[0]=n/m;
    for (int i =1; i <m; i++)
    {
        a[i]=a[0];
    }
    for (int i = 0; i <n%m; i++)
    {
        a[i]++;
    }
    int ji=1;
    for (int i = 0; i <m; i++)
    {
        cout<<a[i]<<' ';
        ji*=a[i];
    }
    cout<<endl<<ji<<endl;
}

//这道题说明剪成m段的时候m>1这个m不固定求最大乘积
//dp[n]=max{dp[i]*d[n-i],dp[n]}
int Figure(int length){
    if(length<2)
        return 0;
    if(length==2)
        return 1;
    if(length==3)
        return 2;
    int *dp=new int[length+1];
    //这些不剪最好
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for (int i = 4; i <=length; i++)
    {
        for (int j = 1; j <=i/2; j++)//割到一半即可
        {
            int max=dp[j]*dp[i-j];
            if(max>dp[i])
                dp[i]=max;
        }
    }
    return dp[length];
}

int main( ){
    cout<< Figure(8);
}
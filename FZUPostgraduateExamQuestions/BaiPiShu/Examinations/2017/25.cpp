#include <iostream>
using namespace std;
//电路布线问题 考虑采用动态规划 size[i][j]表示i点到j点最大无交叉集
//c[i]=j表示i通的到下接线柱为j
//于是最优子结构为size[i][j]={max{size[i-1][j],size[i-1][c[i]-1]+1}}

void SearchMax(int c[], int n)
{
    int size[][];
    //初始化 若c[i]小于j表示无连接点
    for (int i = 1; i <= n; i++)
    {
        if (c[1] > i)
            size[1][i] = 0;
        else
            size[1][i] = 1;
    }
    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (c[i] > j)
                size[i][j] = size[i - 1][j];
            if (size[i - 1][j] > size[i - 1][c[i] - 1] + 1)
                size[i][j] = size[i - 1][j];
            else
                size[i][j] = size[i - 1][c[i] - 1] + 1;
        }
    }
    if (size[n - 1][n] > size[n - 1][c[n] - 1] + 1)
        size[n][n] = size[n - 1][n];
    else
        size[n][n] = size[n - 1][c[n] - 1] + 1;
    TraceBack(size,c,n);
}


//回溯从屁股后面找 碰见指标不一样就找到了 然后按上面递归的回减
void TraceBack(int size[][],int c[],int n){
    int *Nets=new int[n+1];
    int t=c[n];
    for (int i =n; i > 1; i--)
    {
        if(size[i-1][t]!=size[i][t]){
            Nets[i]=1;
            t=c[i-1];
        }
    }
    for (int i = 1; i <=n; i++)
    {
        if(Nets[i])
            cout<<i<<c[i]<<" ";
    }
    cout<<endl<<"最大不相交集为："<<size[n][n];         
}
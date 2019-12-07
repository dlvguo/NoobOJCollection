#include <iostream>
using namespace std;

int max(int a,int b){
    return a>b?a:b;
}

//0-1背包问题
//w[i][j]表示第i个j容量的最大价值
void Bag01(int c[], int n, int total)
{
    int w[][];
    for (int i = 1; i <= total; i++)
    {
        if (c[i] > i)
            w[1][i] = 0;
        else
            w[1][i] = c[i];
    }
    for (int i = 2; i <=n; i++)
    {
        for (int j = 1; i <=total; i++)
        {
            if(c[i]>j)
                w[i][j]=w[i-1][j];
            else
            {
                //若是完全背包可在这加一层 for 1<=k<=j/w[i]
                //或者动态转移方程改成w[i-1][j],w[i][j-c[i]]+c[i] 因为本身可以再次放入
                w[i][j]=max(w[i-1][j],w[i][j-c[i]]+c[i]);
            }
        }
    }
    //此时w[n][total]为最大 
    int t=total;
    for (int i = n; i >=2; i++)
    {
        if(w[i-1][t]==w[i][t])
            continue;
        else{
            cout<<i;
            t-=c[i];
        }
    }
    if(w[1][t])
        cout<<1;
}
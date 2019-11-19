#include <iostream>
using namespace std;

void Sort(int x[], int t[], int n)
{
    for (int i = 1; i <= n; i++)
        t[i] = i;
    for (int i = 1; i < n; i++)
    {
        int temp = i;
        for (int j = i + 1; j <= n; i++)
        {
            if (x[t[i]] > x[t[j]])
            {
                temp = j;
            }
        }
        if (temp != i)
        {
            swap(t[temp], t[i]);
        }
    }
}

//求最优装载问题
void Sum(int x[], int n,int w)
{
    //x[i]表示i中的数量
    //贪心就是将x[i]从小到大排列 为了 留住x[i]顺序 用t[]表示顺序索引如 t[1]=2 表示最轻的为x[2]
    int *t = new int[n + 1];
    int ans=0;
    for (int i = 1; i <=n ; i++)
    {
        if(w>=x[t[i]]){
            ans++;
            w-=x[t[i]];
        }
    }
    for (int i = 1; i <=ans; i++)
    {
        cout<<t[i];
    }
    cout<<" "<<ans<<endl;
}
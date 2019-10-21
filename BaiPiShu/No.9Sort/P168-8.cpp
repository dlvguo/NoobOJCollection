#include<iostream>
#include<cstring>
using namespace std;
//桶排序 本来类似邻接表 根据图中情况只要依次输出 因此重复的++ 即可
void BarrelSort(int a[],int n){
    int *b=new int[n+1];//下标1-n
    memset(a,0,sizeof(int)*(n+1));
    for (int i = 1; i <=n; i++)
    {
        b[a[i]]++;
    }
    for (int i = 1; i <=n; i++)
    {
        if(b[i]){
            while (b[i]--)
            {
                cout<<i<<endl;
            }
        }
    }
}

#include<iostream>
using namespace std;

int SearchKMin(int a[],int n,int k){
    //简单的选择排序
    if(n<k)
        exit(0);
    for (int i = 1 ; i <=k; i++)
    {
        int index=i;
        for (int j = i+1; j <=n; j++)
        {
            if(a[index]>a[j])
                index=j;
        }
        if(index!=i)
            swap(a[i],a[index]);
    }
    return a[k];
}
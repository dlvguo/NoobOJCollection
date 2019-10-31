#include<iostream>
using namespace std;

#define N 55

//简单的O(n2)法
int FigureMax(int a[]){
    //设数组下标1-N
    //从i的前面到i小的话temp++
    int max=0;
    for (int i = 1; i <=N; i++)
    {
        int temp=0;
        for (int j=1; j <=i ; j++)
        {
            if(a[j]<a[i]){
                temp++;
            }
        }
        max=max<temp?temp:max;
    }
    return max;
}

//转变nLogn
//假设b[]是a[]中的最长递增子序列，因此要保证b[]尽可能长 n的Len即位最长子序列长度
int b[];

int BinarySearch(int high,int value){
    int low=1;
    while (low<high)
    {
        int mid=(low+high)/2;
        if(b[mid]<=value)
            low=mid+1;
        else
        {
            high=mid-1;
        }
    }
    return low;
}

int Figure(int a[]){
    int blen=1;
    b[1]=a[1];
    for (int i = 2; i <=N; i++)
    {
        //a[i]大于最后个 说明加入序列
        if(b[blen]<a[i]){
            b[++blen]=a[i];
        }
        //说明a[i]<b[blen],将a[i]中一个大于a[i]的值替换了 即可相对的减少序列
        else{
            b[BinarySearch(blen,a[i])]=a[i];
        }
    }
    
}
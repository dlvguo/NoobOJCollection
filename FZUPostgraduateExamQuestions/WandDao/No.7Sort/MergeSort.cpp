#include<iostream>
using namespace std;

//递归法
void Merge(int low,int high,int a[]){
    int len=high-low+1;
    int *b=new int [high-low+1];
    for (int i = 0,j=low; i < len; i++,low++)
    {
        b[i]=a[low];
    }
    
    int l=0,j=len/2;
    while (l<len/2&&j<=len)
    {
        a[low++]=b[l]<b[j]?b[l++]:b[j++];        
    }
    while (l<len/2)
    {
        a[low++]=a[l++];
    }
    while (j<=len)
    {
        a[low++]=a[j++];
    }    
}

void MergeSort(int low,int high,int a[]){
    if(low<high){
    int mid=(low+high)/2;
    MergeSort(low,mid);
    MergeSort(mid+1,high);
    Merge(low,high,a);
    }
}

//非递归的合并算法是一样的 非递归2 4 8 这些递增来
void Merge_Sort(int n,int a[]){
    int step=2;
    while (step<n)
    {
        //在所有能满组序列的情况下合并
        for (int i = 0; i <n/step; i++)
        {
            Merge(i*step+1,(i+1)*step,a);
        }
        //说明最后不是完成的序列
        if(n%step){
            Merge(n-n%step+1,n);
        }
        step*=2;
    }
}
#include<iostream>
using namespace std;

//插入排序
void InsertSort(int a[],int len){
    for (int i = 2; i <= len; i++)
    {
        //哨兵
        a[0]=a[i];
        int j;
        for (j = i-1; a[j]>a[0]; j--)
        {
            a[j+1]=a[j];
        }
        //注意指针
        if(j!=0)
            a[j+1]=a[0];
    }    
}
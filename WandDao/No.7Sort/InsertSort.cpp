#include<iostream>
using namespace std;

//插入排序
void InsertSort(int a[],int len){
    
    for (int i = 2; i <= len; i++)
    {
        a[0]=a[i];
        int j;
        for (j = i-1; a[j]>a[i]; j--)
        {
            a[j+1]=a[j];
        }
        if(j!=0)
            a[j]=a[0];
    }    
}
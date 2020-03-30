#include<iostream>
using namespace std;

void SelectSort(int a[],int n){
    for (int i = 1; i <=n ; i++)
    {
        int index=i;
       for (int j = i+1; j <= n; j++)
       {
           if(a[index]>a[j])
            index=j;
       }
       if(index!=i){
           int temp=a[index];
           a[index]=a[i];
           a[i]=temp;
       }
    }
}
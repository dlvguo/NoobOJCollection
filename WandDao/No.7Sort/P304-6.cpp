#include<iostream>
using namespace std;

void CreateTwoCollection(int *A,int n,int * &A1,int *& A2){
   //将最小的放入n/2个数放入A1中,剩下的放入A2中
   //就用选择吧 但感觉应该不是最简单的
   A1=new int[n/2];   
   A2=new int[n%2?n/2+1:n/2];
   for (int i =1; i <=n/2; i++)
   {
       int index=i;
       for (int j = i+1; j <=n; j++)
       {
           if(A[index]>A[j])
            index=j;
       }
       if(i!=index)
       swap(A[i],A[index]);
       A1[i]=A[index];
   }
   for (int i = n/2+1; i <=n; i++)
   {
       A2[i]=A[i];
   }
}
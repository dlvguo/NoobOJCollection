#include <iostream>
using namespace std;

void BubbleSort(int a[], int len)
{
    int flag;
    for (int i = 0; i <len; i++)
    {
        flag=false;
        for (int j = 1; j < len-i; j++)
        {
            if(a[j]<a[j-1]){
                int temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
                flag=true;
            }
        }
        if(!flag)
            return;
    }
    
}
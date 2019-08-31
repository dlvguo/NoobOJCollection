#include <iostream>
#include "../../Headers/array.h"
using namespace std;

void Reverse(int a[],int len)
{
    int low=0,high=len-1;
    while (low<high)
    {
        while (low<high&&a[low]<0)
        {
            low++;
        }
        while (low<high&&a[high]>0)
        {
            high--;
        }
        if(low<high){
            int temp=a[low];
            a[low]=a[high];
            a[high]=temp;
            low++;
            high--;
        }   
    }
}

int main()
{
    freopen("C:/NoobOJCollection/BaiPiShu/XianXingBiao/P92-4.txt", "r", stdin);
    int *a=CreatyIntArr(6);
    Reverse(a,6);
    PrintArr(a,6);
    return 0;
}
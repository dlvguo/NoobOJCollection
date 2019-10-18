#include <iostream>
using namespace std;

//接口返回low-high之间的数
int Random(int low,int high);
//交换
void Swap(int &a,int &b);

void RandomPartition(int a[], int low,int high)
{
    //返回low-high之后一个数    
    int randomindex=Random(low,high);
    //让a[low]与这个数交换
    Swap(a[low],a[randomindex]);
    int pivot=a[low];
    //利用快排思想  
    while (low < high)
    {
        while (low<high&&a[high]>=pivot)
        {
            high--;
        }
        a[low]=a[high];
        while (low<high&&a[low]<=pivot)
        {
            low++;
        }
        a[high]=a[low];
    }
    a[low]=pivot;
}

void QuickSort(int a[],int low,int high){
    if(low<high){
        int portition=RandomPartition(a,low,high);
        QuickSort(a,low,portition-1);
        QuickSort(a,portition+1,high);
    }
}
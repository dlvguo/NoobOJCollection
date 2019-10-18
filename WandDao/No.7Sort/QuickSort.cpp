#include <iostream>
using namespace std;

int Partition(int a[], int low, int high)
{
    int pivot = a[low];
    while (low < high)
    {
        while (low < high && a[high] >= pivot)
            high--;
        a[low]=a[high];
        while (low<high&&a[low]<=pivot)
            low++;
        a[high]=a[low];
    }
    a[low]=pivot;
    return low;
}

//快速排序
void QucikSort(int a[], int low, int high)
{
    if(low<high){
        int portition=Partition(a,low,high);
        QucikSort(a,low,portition-1);
        QucikSort(a,portition+1,high);
    }
}
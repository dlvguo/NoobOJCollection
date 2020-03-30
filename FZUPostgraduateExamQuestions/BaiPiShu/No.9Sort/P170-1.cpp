#include <iostream>
using namespace std;

void QuickSort(int a[], int len)
{
    int low = 1, high = len, povit, top = -1;
    int *stack = new int[len];
    while (low < high || top != -1)
    {
        int low0 = low, high0 = high;
        while (low0 < high0)
        {
            povit = a[low0];
            while (low0 < high0 && a[high0] >= povit)
            {
                high0--;
            }
            a[low0] = a[high0];
            while (low0 < high0 && a[low0] <= povit)
            {
                low0++;
            }
            a[high0] = a[low0];
            a[low0] = povit;
        }
        //先看要不要放入
        if(low0+1!=high||low0==high){
            stack[++top]=low0+1;
            stack[++top]=high;
        }
        //说明左边元素排序好了 出栈
        if(low0-1==low||low0==low){
            high=stack[top--];
            low=stack[top--];
        }
        //否则继续左边
        else{
            high=low0-;
        }
    }
}
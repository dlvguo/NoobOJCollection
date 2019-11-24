#include <iostream>
using namespace std;
//快排改进 一种就是避免相同的数过度集中 于是在小于等于 或者大于等于的时候就交换
//还有一种中位数 区间小于某一段用其他排序  随机选择锚点 还有一种三路快排
//避免最坏情况的快排 O(nlogn)
//找基准中位数 把最大

//把中位数放在a[low]位置
void FindMid(int a[], int low, int high)
{
    int mid = (low + high) / 2;
    if (a[low] < a[high] && a[low] > a[mid] || a[low] > a[low] && a[low] > a[mid])
    {
        return;
    }
    else if (a[mid] > a[low] && a[mid] < a[high] || a[mid] > a[high] && a[mid] < a[low])
        swap(a[low], a[mid]);
    else
    {
        swap(a[high], a[low]);
    }
}
//选择排序 当小于Min的时候
void InsertSort(int a[], int low, int high)
{
    for (int i = low + 1; i <= high; i++)
    {
        a[0] = a[i];
        for (int j = i; j > low; i--)
        {
            if (a[0] >= a[j - 1])
            {
                a[j] = a[0];
            }
            else
            {
                a[j] = a[j - 1];
            }
        }
    }
}
#define MIN 3
int Portion(int a[], int low, int high)
{
    FindMid(a, low, high);
    int pivot = a[low];
    while (low < high)
    {
        while (low < high && pivot <= a[high])
            high--;
        a[low] = a[high];
        while (low < high && pivot >= a[low])
            low++;
        a[high]=a[low];
    }
    a[low]=pivot;
    return low;
}

void ImproveQuickSort(int a[], int low, int high)
{
    if (low >= high)
        return;
    if ((high - low) <= MIN)
        InsertSort(a, low, high);
    else
    {
        int pos = Portion(a, low, high);
        ImproveQuickSort(a, low, pos - 1);
        ImproveQuickSort(a, pos + 1, high);
    }
}

//三路快排 因为有俩个区间就不选Partion路径 就一个算法搞定了
void ThreeQuickSort(int a[], int low, int high)
{
    if (low >= high)
        return;
    //i表示前面都小于pivot j表示后面都大于pivot 则i-j相等不做排序
    int i = low, j = high, pivot = a[low], p = low;
    while (p <= j)
    {
        if (a[p] < pivot)
        {
            swap(a[i], a[p]);
            i++;
            p++;
        }
        else if (a[p] > pivot)
        {
            swap(a[j], a[p]);
            j--;
        }
        else
        {
            p++;
        }
    }
    ThreeQuickSort(a, low, i - 1);
    ThreeQuickSort(a, j + 1, high);
}
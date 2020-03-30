#include <iostream>
using namespace std;

//这个要o(n平方)
void CreateTwoCollection(int *A, int n, int *&A1, int *&A2)
{
    //将最小的放入n/2个数放入A1中,剩下的放入A2中
    //就用选择吧 但感觉应该不是最简单的
    A1 = new int[n / 2];
    A2 = new int[n % 2 ? n / 2 + 1 : n / 2];
    for (int i = 1; i <= n / 2; i++)
    {
        int index = i;
        for (int j = i + 1; j <= n; j++)
        {
            if (A[index] > A[j])
                index = j;
        }
        if (i != index)
            swap(A[i], A[index]);
        A1[i] = A[index];
    }
    for (int i = n / 2 + 1; i <= n; i++)
    {
        A2[i] = A[i];
    }
}

//利用快排只需要调整到pivot为n/2 即可时间复杂度为O(n)
int SearchDifference(int a[], int n)
{
    int i = n / 2, low = 1, high = n,pivot;
    //当pivot==i时,排序完成
    //pivot<i 则向右
    //pivit>i 则左
    while (i != low)
    {
        pivot = a[low];

        while (low < high)
        {
            while (low < high && a[high] >= pivot)
            {
                high--;
            }
            a[low] = a[high];
            while (low < high && a[low] <= pivot)
            {
                low++;
            }
            a[high] = a[low];
        }
        a[low] = pivot;
        if (low > i)
        {
            high = low - 1;
            low = 1;
        }
        else if (low < i)
        {
            low++;
        }
    }
    int s = 0;
    for (int i = 1; i <= k; i++)
    {
        s += a[i];
    }
    for (int i = k + 1; i <= n; i++)
    {
        s -= a[i];
    }
    return s > 0 ? s : -1 * s;
}
#include <iostream>
using namespace std; //计数排序 若数组内数字<=n 可用数组计数而非那种n累加法

void CountSort(int a[], int n)
{
    int *b = new int[n + 1];
    //初始化
    for (int i = 1; i <= n; i++)
    {
        b[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        b[a[i]]++;
    }
    //倒叙放入避免导致不稳定
    for (int i = n, j = n; i > 0; i++)
    {
        while (b[i]--)
        {
            a[j--] = i;
        }
    }
}

#include <iostream>
using namespace std;

//插入排序
void ShellSort(int a[], int len)
{
    //增量dk从len/2 一直到1 类似插入
    for (int dk = len / 2; dk >= 1; dk--)
    {
        for (int i = dk + 1; i <= len; i++)
        {
            if (a[i] < a[i - dk])
            {
                a[0] = a[i];//非哨兵只是暂存
                int j;
                for (j = i - dk; j > 0 && a[j] > a[0]; j -= dk)
                {
                    a[j+dk]=a[j];
                }
                if(j>0){
                    a[j+dk]=a[0];
                }

            }
        }
    }
}
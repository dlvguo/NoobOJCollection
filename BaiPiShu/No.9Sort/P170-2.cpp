#include <iostream>
using namespace std;

//计数排序
void CountSort(int a[], int len)
{
    //创建一个新的数组赋值为0
    int *b = new int[len + 1];
    for (int i = 1; i <= len; i++)
    {
        b[i] = 0;
    }
    for (int i = 1; i <= len; i++)
    {
        int count = 0;
        for (int j = 1; j <= len; j++)
        {
            if (a[j] < a[i])
                count++;
        }
        //如果有相同元素占据位置找到下一个未占用的地方
        while (b[count])
        {
            count++;
        }
        b[count + 1] = a[i];
    }
    for (int i = 1; i <= len; i++)
    {
        a[i] = b[i];
    }
}

//升级版计算排序 若只跟后面次数比较则需要自定义结构体

typedef struct reftype
{
    int key;
    int count = 0;
};
void CounfSort(reftype r[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (r[i].key < a[j].key)
                r[i].count++;
            else
                r[j].count++;
        }
    }
}
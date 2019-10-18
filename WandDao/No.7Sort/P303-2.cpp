#include <iostream>
using namespace std;

void DoubleMP(int a[], int len)
{
    //假设数组下标从1-n
    int low = 1, high = len;
    while (low < high)
    {
        int flag = false;
        //假设从小到大排列
        for (int i = low; i < high; i++)
        {
            if (a[i] > a[i + 1])
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                flag = true;
            }
        }
        high--;
        if (!flag)
            return;
        flag = false;
        for (int i = high; i > low; i--)
        {
            if (a[i] < a[i - 1])
            {
                int temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;
                flag = true;
            }
        }
        low++;
        if (!flag)
            return;
    }
}
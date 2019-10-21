#include <iostream>
using namespace std;

void DoubleBubble(int a[], int len)
{
    int low = 1, high = len, flag = 1;
    //递减排列
    while (low < high && flag)
    {
        flag = 0;
        for (int i = low; i < high; i++)
        {
            if (a[i] < a[i + 1])
            {
                swap(a[i], a[i + 1]);
                flag = 1;
            }
        }
        high--;
        for (int i = high; i > low; i++)
        {
            if (a[i] > a[i - 1])
            {
                swap(a[i], a[i - 1]);
                flag = 1;
            }
        }
        low++;
    }
}
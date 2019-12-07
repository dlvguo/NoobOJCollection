#include <iostream>
#include <algorithm>
using namespace std;

int cmp(const int a, const int b)
{
    return a > b ?
}

int Figuer(int candy[], int kid[], int n)
{
    //将candy[]从和kid[]从大到小排列 尽可能满足序列
    qsort(candy, n, sizeof(int), cmp);
    qsort(kid, n, sizeof(int), cmp);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; i++)
        {
            if (candy[j] >= kid[i])
            {
                candy -= kid[i];
                sum++;
                break;
            }
        }
    }
    return sum;
}
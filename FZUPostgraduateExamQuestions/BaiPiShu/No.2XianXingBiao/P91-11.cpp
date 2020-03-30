#include <iostream>
#include "../Headers/linkList.h"
#include "../Headers/array.h"
using namespace std;

int AscAB(int a[], int n, int s, int l)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= s && a[i] <= l)
        {
            count++;
        }
        else
        {
            a[i - count] = a[i];
        }
    }
    return n - count;
}

int main()
{
    freopen("C:/NoobOJCollection/BaiPiShu/XianXingBiao/P91-11.txt", "r", stdin);
    int *a = CreatyIntArr(5);
    
    return 0;
}
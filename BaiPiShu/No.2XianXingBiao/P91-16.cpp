#include <iostream>
#include "../../Headers/array.h"
using namespace std;

//考虑俩种情况 1、2
void FindIndex(int a[], int alen, int b[], int blen, int k)
{
    int count = 0, alow = 0, blow = 0;
    if (alen + blen < k || k < 1)
    {
        cout << "Don't exit" << endl;
        return;
    }
    while (alow < alen && blow < blen)
    {
        count++;
        if (a[alow] <= b[blow])
        {
            if (count == k)
            {
                cout << a[alow] << endl;
                return;
            }
            alow++;
        }
        else
        {
            if (count == k)
            {
                cout << b[blow] << endl;
                return;
            }
            blow++;
        }
    }
    while (alow < alen)
    {
        count++;
        if (count == k)
        {
            cout << a[alow] << endl;
            return;
        }
        alow++;
    }
    while (blow < blen)
    {
        count++;
        if (count == k)
        {
            cout << b[blow] << endl;
            return;
        }
        blow++;
    }
}

int main()
{
    freopen("C:/NoobOJCollection/BaiPiShu/XianXingBiao/P91-15.txt", "r", stdin);
    int *a = CreatyIntArr(6), *b = CreatyIntArr(5);
    FindIndex(a, 6, b, 5, 11);
    return 0;
}
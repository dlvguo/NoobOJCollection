#include <iostream>
using namespace std;

//错了应该类似八皇后全部遍历
void PrintAll(int a[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
        for (int k = i + 1; k <= n; k++)
            for (int j = k; j <= n; j++)
                cout << a[j];
    }
}

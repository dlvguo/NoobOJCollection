#include <iostream>
#include <algorithm>
using namespace std;

int a[1000007];

int main()
{
    int n;
    while (scanf("%d", &n)!=EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1])
            {
                cout << a[i] << endl;
                break;
            }
        }
    }
}
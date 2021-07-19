#include <bits/stdc++.h>
using namespace std;

int checkset[100005] = {-1};

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int a, b;
    for (int i = 1; i <= n; i++)
    {
        checkset[i] = i;
    }

    while (m--)
    {
        scanf("%d%d", &a, &b);
        checkset[b] = a;
    }
    int num = 0;
    for (int i = 1; i <= n; i++)
    {
        if (checkset[i] == i)
            num++;
    }
    cout << num << endl;
}
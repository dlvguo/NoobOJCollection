#include <bits/stdc++.h>
using namespace std;

int cuttingRope(int n)
{
    if (n == 2)
        return 1;
    if (n == 3)
    {
        return 2;
    }
    int mod = n % 3;

    long long sum = 1;
    if (mod == 1)
    {
        n -= 4;
        mod += 3;
    }
    else if (mod == 0)
        mod = 1;
    for (int i = 0; i < n / 3; i++)
    {
        sum = (sum * 3) % 1000000007;
    }
    return (int)(sum * mod % 1000000007);
}
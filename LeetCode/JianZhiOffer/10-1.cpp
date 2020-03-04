#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000007

long long _fib[101] = {0, 1};

int fib(int n)
{
    for (int i = 2; i <=n; i++)
    {
        _fib[i]=(_fib[i-1]+_fib[i-2])%MAX;
    }
    return _fib[n];
}
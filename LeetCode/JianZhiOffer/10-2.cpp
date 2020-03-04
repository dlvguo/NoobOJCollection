#include <bits/stdc++.h>
using namespace std;

long long step[101] = {0, 1, 2};
long long MAX = 1000000007;

int numWays(int n)
{
    for (int i = 3; i <= n; i++)
    {
        step[i] = (step[i - 1] + step[i - 2]);
        while (step[i] >= MAX)
        {
            step[i] -= MAX;
        }
    }
    return step[n];
}
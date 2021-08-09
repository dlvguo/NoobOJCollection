#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int tribonacci(int n)
    {
        int a[38] = {0, 1, 1};
        for (int i = 3; i <= n; i++)
            a[i] = a[i - 1] + a[i - 2] + a[i - 3];
        return a[n];
    }
};
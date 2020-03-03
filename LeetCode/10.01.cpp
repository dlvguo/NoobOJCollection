#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &A, int m, vector<int> &B, int n)
{
    int totalLen = m + n - 1;
    m--;
    n--;
    while (m >= 0 && n >= 0)
    {
        if (A[m] >= B[n])
        {
            A[totalLen--] = A[m--];
        }
        else
        {
            A[totalLen--] = B[n--];
        }
    }
    while (m>=0)
    {
            A[totalLen--] = A[m--];
    }
    while (n>=0)
    {
            A[totalLen--] = B[n--];
    }
}
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &A, int K)
    {
        int index = A.size() - 1, dig = 0;
        while (index >= 0 && K)
        {
            A[index] = A[index] + K % 10 + dig;
            dig = A[index] / 10;
            A[index--] %= 10;
            K /= 10;
        }
        if (index < 0)
        {
            K += dig;
            while (K)
            {
                A.insert(A.begin(), K % 10);
                K /= 10;
            }
        }
        else
        {
            while (index >= 0 && dig)
            {
                A[index] += dig;
                dig = A[index] / 10;
                A[index--] %= 10;
            }
            if (dig)
            {
                A.insert(A.begin(), 1);
            }
        }
        return A;
    }
};
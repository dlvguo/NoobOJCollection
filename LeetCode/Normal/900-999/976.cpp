#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largestPerimeter(vector<int> &A)
    {
        sort(A.begin(), A.end());
        for (int i = A.size() - 1, j = A.size() - 2; j >= 1; i--, j--)
        {
            if (A[i] - A[j] < A[j - 1])
            {
                return A[i] + A[j] + A[j - 1];
            }
        }
        return 0;
    }
};
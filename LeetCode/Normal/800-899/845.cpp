#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestMountain(vector<int> &A)
    {
        int n = A.size();
        if (!n)
        {
            return 0;
        }
        vector<int> left(n);
        for (int i = 1; i < n; ++i)
        {
            left[i] = (A[i - 1] < A[i] ? left[i - 1] + 1 : 0);
        }
        vector<int> right(n);
        for (int i = n - 2; i >= 0; --i)
        {
            right[i] = (A[i + 1] < A[i] ? right[i + 1] + 1 : 0);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (left[i] > 0 && right[i] > 0)
            {
                ans = max(ans, left[i] + right[i] + 1);
            }
        }
        return ans;
    }
};
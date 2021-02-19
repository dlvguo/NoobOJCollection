#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &A, int K)
    {
        int l = 0, r = 0, z = 0, _max = 0;
        for (; r < A.size(); r++)
        {
            if (A[r] == 0)
                z++;
            if (z > K && A[l++] == 0)
                z--;
        }
        return r-l;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkAsc(vector<int> &A)
    {
        for (int i = 1; i < A.size(); i++)
        {
            if (A[i - 1] > A[i])
                return false;
        }
        return true;
    }

    bool checkDec(vector<int> &A)
    {
        for (int i = 1; i < A.size(); i++)
        {
            if (A[i - 1] < A[i])
                return false;
        }
        return true;
    }

    bool isMonotonic(vector<int> &A)
    {
        if (A.size() == 1)
            return true;
        if (A[0] > A[1])
            return checkDec(A);
        else if (A[0] < A[1])
            return checkAsc(A);
        return checkDec(A) || checkAsc(A);
    }
};
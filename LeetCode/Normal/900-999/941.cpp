#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validMountainArray(vector<int> &A)
    {
        int l = 0, r = A.size() - 1;
        while (l + 1 < A.size() && A[l] < A[l + 1])
        {
            l++;
        }
        if (!l)
            return false;
        while (r - 1 >= 0 && A[r - 1] > A[r])
        {
            r--;
        }
        if (r == A.size() - 1)
            return false;
        return l == r;
    }
};

int main()
{
    Solution s;
    vector<int> n = {2, 1};
    s.validMountainArray(n);
}
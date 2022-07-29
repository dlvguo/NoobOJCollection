#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int convertInteger(int A, int B)
    {
        unsigned int m = A ^ B;
        int cnt = 0;
        while (m)
        {
            cnt++;
            m = m & (m - 1);
        }
        return cnt;
    }
};

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSteps(int n)
    {
        int res = 0, m = n;
        for (int i = 2; i <= n; i++)
        {
            while (m % i == 0)
            {
                res += i;
                m /= i;
            }
        }
        return res;
    }
};

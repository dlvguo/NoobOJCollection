#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> printNumbers(int n)
    {
        if (n == 0)
            return {};
        int num = 1;
        for (int i = 0; i < n; i++)
        {
            num *= 10;
        }

        vector<int> v(num - 1);
        for (int i = 1; i <= num - 1; i++)
        {
            v[i - 1] = i;
        }
        return v;
    }
};
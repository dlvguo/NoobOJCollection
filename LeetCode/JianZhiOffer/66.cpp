#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> constructArr(vector<int> &a)
    {
        if (a.size() <= 1)
            return {};
        vector<int> b(a.size());
        //从左往右乘
        int temp = a[0];
        b[0] = 1;
        for (int i = 1; i < a.size(); i++)
        {
            b[i] = temp;
            temp *= a[i];
        }
        //从右往左乘  注意边界
        temp = a.back();
        for (int i = a.size() - 2; i >= 0; i--)
        {
            b[i] *= temp;
            temp *= a[i];
        }
        return b;
    }
};
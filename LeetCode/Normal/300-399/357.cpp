#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        int temp = 1;
        int res = 0;
        int data[10] = {1, 9, 9, 8, 7, 6, 5, 4, 3, 2};
        for (int i = 0; i <= n; i++)
        {
            temp *= data[i];
            res += temp;
        }
        return res;
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        //注意excel 后面的位
        long long mul = 1;
        int total = 0;
        for (int i = columnTitle.size() - 1; i >= 0; i--)
        {
            int n = columnTitle[i] - 'A' + 1;
            total += n * mul;
            mul *= 26;
        }
        return total;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int translateNum(int num)
    {
        if (num < 10)
            return 1;
        if (num%100>9&&num % 100 < 26)
            return translateNum(num / 100) + translateNum(num / 10);
        return translateNum(num / 10);
    }
};
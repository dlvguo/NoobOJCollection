#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int num = digits.size() - 1;
        int dig = 1;
        while (num >= 0 && dig)
        {
            digits[num] += dig;
            dig = digits[num] / 10;
            digits[num--] %= 10;
        }
        if (!dig)
            return digits;
        digits.insert(digits.begin(), 1, 1);
        return digits;
    }
};
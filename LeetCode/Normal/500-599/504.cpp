#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string convertToBase7(int num)
    {
        if (num == 0)
            return "0";
        string res = "";
        string res2 = "";
        if (num < 0)
        {
            res += "-";
            num = -num;
        }
        while (num)
        {
            res2.push_back(num % 7 + '0');
            num /= 7;
        }
        reverse(res2.begin(), res2.end());
        return res + res2;
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string v[14] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int k[14] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string intToRoman(int num)
    {
        string str;
        int index = 0;
        while (num > 0)
        {
            if (num >= k[index])
            {
                str += v[index];
                num -= k[index];
            }
            else
            {
                index++;
            }
        }
        return str;
    }
};
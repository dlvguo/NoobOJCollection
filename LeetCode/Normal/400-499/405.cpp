#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0)
        {
            return "0";
        }
        string sb;
        for (int i = 7; i >= 0; i--)
        {
            int val = (num >> (4 * i)) & 0xf;
            if (sb.length() > 0 || val > 0)
            {
                char digit = val < 10 ? (char)('0' + val) : (char)('a' + val - 10);
                sb.push_back(digit);
            }
        }
        return sb;
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        long long num = numerator, den = denominator;
        string ans;
        long long bit = num * den;
        num = abs(num), den = abs(den);

        if (bit == 0)
            return "0";

        if (bit < 0)
            ans += "-";

        long long pre = num / den;
        ans += to_string(pre);

        if (num % den == 0)
            return ans;

        ans += '.';
        num = num - (num / den) * den;

        int index = ans.size();
        unordered_map<int, int> pos;
        while (num && (pos.find(num) == pos.end()))
        {
            pos[num] = index++;
            num *= 10;
            ans += char('0' + num / den);
            num = num - (num / den) * den;
        }
        if (num != 0)
        {
            int last_pos = pos[num];
            ans = ans.substr(0, last_pos) + '(' + ans.substr(last_pos) + ')';
        }
        return ans;
    }
};
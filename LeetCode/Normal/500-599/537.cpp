#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string complexNumberMultiply(string num1, string num2)
    {
        int n1 = 0, f1 = 1, n2 = 0, f2 = 1;
        int _n1 = 0, _f1 = 1, _n2 = 0, _f2 = 1;
        // 算第一个数
        int index = 0;
        if (num1[0] == '-')
        {
            index++;
            f1 = -1;
        }
        while (index < num1.size() && num1[index] != '+')
        {
            n1 = n1 * 10 + (num1[index++] - '0');
        }
        n1 *= f1;
        if (num1[index + 1] == '-')
        {
            f2 = -1;
            index += 2;
        }
        else
            index++;
        while (index < num1.size() && num1[index] != 'i')
        {
            n2 = n2 * 10 + (num1[index++] - '0');
        }
        n2 *= f2;

        // 算第二个数
        index = 0;
        if (num2[0] == '-')
        {
            index++;
            _f1 = -1;
        }
        while (index < num2.size() && num2[index] != '+')
        {
            _n1 = _n1 * 10 + (num2[index++] - '0');
        }
        _n1 *= _f1;
        if (num2[index + 1] == '-')
        {
            index += 2;
            _f2 = -1;
        }
        else
            index++;
        while (index < num2.size() && num2[index] != 'i')
        {
            _n2 = _n2 * 10 + (num2[index++] - '0');
        }
        _n2 *= _f2;

        int num = n1 * _n1 - n2 * _n2, num2s = n1 * _n2 + n2 * _n1;
        return to_string(num) + "+" + to_string(num2s) + "i";
    }
};
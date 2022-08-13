#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string solveEquation(string equation)
    {
        int factor = 0, val = 0;
        int index = 0, n = equation.size(), sign1 = 1; // 等式左边默认系数为正
        while (index < n)
        {
            if (equation[index] == '=')
            {
                sign1 = -1; // 等式右边默认系数为负
                index++;
                continue;
            }

            int sign2 = sign1, number = 0;
            bool valid = false; // 记录 number 是否有效
            if (equation[index] == '-' || equation[index] == '+')
            { // 去掉前面的符号
                sign2 = (equation[index] == '-') ? -sign1 : sign1;
                index++;
            }
            while (index < n && isdigit(equation[index]))
            {
                number = number * 10 + (equation[index] - '0');
                index++;
                valid = true;
            }

            if (index < n && equation[index] == 'x')
            { // 变量
                factor += valid ? sign2 * number : sign2;
                index++;
            }
            else
            { // 数值
                val += sign2 * number;
            }
        }

        if (factor == 0)
        {
            return val == 0 ? "Infinite solutions" : "No solution";
        }
        return string("x=") + to_string(-val / factor);
    }
};

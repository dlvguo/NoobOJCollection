#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        int index = 0;
        int flag = 1;
        while (index < str.size() && str[index] == ' ')
        {
            index++;
        }
        if (index == str.size())
            return 0;
        if (str[index] == '-')
        {
            flag = -1;
            index++;
        }
        else if (str[index] == '+')
            index++;

        if (index == str.size() || str[index] < '0' || str[index] > '9')
            return 0;
        long long sum = 0;
        //找到第一个非空白字符了
        while (index < str.size() && str[index] >= '0' && str[index] <= '9')
        {
            sum = sum * 10 + str[index++] - '0';
            if (sum > 2147483647)
            {
                if (flag > 0)
                    return INT_MAX;
                return INT_MIN;
            }
        }
        return (int)flag * sum;
    }
};
#include <iostream>
#include <cstring>
using namespace std;

int romanToInt(string s)
{
    //""MMCCCXCIX""
    int sum = 0;
    int i = s.length() - 1;
    while (i >= 1)
    {
        if (s[i] == 'I')
            sum += 1;
        else if (s[i] == 'V')
        {
            if (s[i - 1] == 'I')
            {
                sum += 4;
                i -= 2;
                continue;
            }
            sum += 5;
        }
        else if (s[i] == 'X')
        {
            if (s[i - 1] == 'I')
            {
                sum += 9;
                i -= 2;
                continue;
            }
            sum += 10;
        }
        else if (s[i] == 'L')
        {
            if (s[i - 1] == 'X')
            {
                sum += 40;
                i -= 2;
                continue;
            }
            sum += 50;
        }
        else if (s[i] == 'C')
        {
            if (s[i - 1] == 'X')
            {
                sum += 90;
                i -= 2;
                continue;
            }
            sum += 100;
        }
        else if (s[i] == 'D')
        {
            if (s[i - 1] == 'C')
            {
                sum += 400;
                i -= 2;
                continue;
            }
            sum += 500;
        }
        else
        {
            if (s[i - 1] == 'C')
            {
                sum += 900;
                i -= 2;
                continue;
            }
            sum += 1000;
        }
        i--;
    }
    if (i == 0)
    {
        switch (s[0])
        {
        case 'I':
            sum += 1;
            break;
        case 'V':
            sum += 5;
            break;
        case 'X':
            sum += 10;
            break;
        case 'L':
            sum += 50;
            break;
        case 'C':
            sum += 100;
            break;
        case 'D':
            sum += 500;
            break;
        default:
            sum += 1000;
            break;
        }
    }
    return sum;
    //避免判断！=0 的情况
}
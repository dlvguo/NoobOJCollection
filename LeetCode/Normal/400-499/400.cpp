#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findNthDigit(int n)
    {
        // 计算是几位数
        long long num = 9, dig = 1, snum = 1;
        while (n > num * dig)
        {
            n -= num * dig;
            dig++;
            num = num * 10;
            snum *= 10;
        }
        // 计算第几个数
        num = snum + n / dig;
        if (n % dig == 0)
            return (num - 1) % 10;
        dig = n % dig;
        while (dig > 1)
        {
            snum /= 10;
            dig--;
        }
        return num / snum % 10;
    }
};
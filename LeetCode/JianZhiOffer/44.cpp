#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findNthDigit(int n)
    {
        if (n <= 9)
            return n;
        n -= 9;
        long long count = 90, dig = 2;
        //计算数位
        while (n > count * dig)
        {
            n -= (count * dig);
            count *= 10;
            dig++;
        }
        //寻找对应的那个数字
        long long num = pow(10, dig - 1) + n / dig;
        //如果刚好这个数字是在最后一位那就是上一个数字的最后一位 例如n 11 计算出来按道理是11，其实对应的是10的0
        if (n % dig == 0)
        {
            num--;
            return num % 10;
        }
        else
        { //如果是这个数的第二位例如 7888 那么应该78/100%10
            for (int i = 0; i < (dig - n % dig); i++)
            {
                num /= 10;
            }
            return num % 10;
        }
    }
};

int main()
{
    Solution s1;
    s1.findNthDigit(10);
}
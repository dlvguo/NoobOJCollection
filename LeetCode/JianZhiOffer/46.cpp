#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int count;

    void TrcaceBack(int num)
    {
        //说明一个数字计算完成
        if (!num)
        {
            count++;
            return;
        }
        //说明该数字能够分解为2位数 并且506中06不属于这个范围
        if (num % 100 < 26 && num % 100 > 9)
            TrcaceBack(num / 100);
        //一位数计算次数，只要不为0肯定都可以计算一次
        TrcaceBack(num / 10);
    }

    int translateNum(int num)
    {
        count = 0;
        TrcaceBack(num);
        return count;
    }
};
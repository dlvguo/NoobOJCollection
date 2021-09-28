#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //a^b是无进位的结果 a&b是有进位的结果 求出之后不断迭代 直至为0
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            unsigned int carry = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};

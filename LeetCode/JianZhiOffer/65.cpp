#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int add(int a, int b)
    {
        while (b != 0)
        {
            int temp = a ^ b;               //除去相加位需要进位
            b = (unsigned int)(a & b) << 1; //进位 c++不支持复述左移 于是专程无符号int
            a = temp;
        }
        return a;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        int sum, count = 0;
        while (n != 1 && count < 500)
        {
            sum = 0;
            while (n)
            {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
            count++;
        }
        return n == 1;
    }
};
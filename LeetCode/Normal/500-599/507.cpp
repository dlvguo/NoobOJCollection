#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        if (num == 1)
            return false;
        int res = 1;
        for (int i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0)
            {
                res += i + num / i;
            }
        }
        return res == num;
    }
};
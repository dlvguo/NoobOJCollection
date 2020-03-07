#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        //就是/2的问题 主要考虑-int32的问题 
        if (n == 0)
            return 1;
        else if (n == 1)
            return x;
        else if (n < 0)
        {
            double half = myPow(x, (n / 2) * -1);
            if (n % 2)
            {
                return 1.0 / (x * half * half);
            }
            return 1.0 / (half * half);
        }
        double half = myPow(x, n / 2);
        if (n % 2)
        {
            return x * half * half;
        }
        return half * half;
    }
};

int main()
{
}
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        int index = 1;
        if (!(n & 1))
            index = 0;
        while (n)
        {
            if (n & 1)
            {
                if (!index)
                {
                    return false;
                }
            }
            else
            {
                if (index)
                    return false;
            }
            index=(index+1)%2;
            n=n>>1;
        }
        return true;
    }
};
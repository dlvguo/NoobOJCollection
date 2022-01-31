#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfSteps(int num)
    {
        int step = 0;
        while (num)
        {
            if (num & 1)
                num--;
            else
                num /= 2;
            step++;
        }
        return step;
    }
};
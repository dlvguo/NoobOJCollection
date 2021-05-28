#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int num = 0;
        while (x || y)
        {
            if (x % 2 != y % 2)
                num++;
            x = x >> 1;
            y = y >> 1;
        }
        return num;
    }
};
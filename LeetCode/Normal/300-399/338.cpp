#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countOnes(int x)
    {
        int ones = 0;
        while (x > 0)
        {
            x &= (x - 1);
            ones++;
        }
        return ones;
    }

    vector<int> countBits(int num)
    {
        vector<int> bits(num + 1);
        for (int i = 0; i <= num; i++)
        {
            bits[i] = countOnes(i);
        }
        return bits;
    }
};

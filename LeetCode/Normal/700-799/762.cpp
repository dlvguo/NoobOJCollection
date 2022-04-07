#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int zs[35] = {0, 0, 1};
    int countPrimeSetBits(int left, int right)
    {
        for (int i = 3; i <= 32; i++)
        {
            bool tag = true;
            for (int j = 2; j <= sqrt(i); j++)
            {
                if (i % j == 0)
                {
                    tag = false;
                    break;
                }
            }
            if (tag)
                zs[i] = 1;
        }
        int ans = 0;
        for (int i = left; i <= right; i++)
        {
            int temp = i, c = 0;
            while (temp)
            {
                c++;
                temp &= (temp - 1);
            }
            if (zs[c])
                ans++;
        }
        return ans;
    }
};
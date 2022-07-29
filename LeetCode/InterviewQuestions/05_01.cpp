#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int insertBits(int N, int M, int i, int j)
    {
        for (int k = i; k <= j; k++)
        {
            N &= (~(1 << k));
        }
        // 注意顺序
        return N + (M << i);
    }
};
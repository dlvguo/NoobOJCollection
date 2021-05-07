#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int xorOperation(int n, int start)
    {
        int num = start;
        for (int i = 1; i < n; i++)
        {
            num ^= start + i * 2;
        }
        return num;
    }
};
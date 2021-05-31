#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        //移除最低位置的 1
        return n > 0 && (n & (n - 1)) == 0;
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int reverseBits(int num)
    {
        if (~num == 0)
            return 32; //全是1的情况，若不特判会输出33

        int curLen = 0, preLen = 0;
        int maxLen = 1; //最少也能翻转1位

        for (int i = 0; i < 32; ++i)
        {
            if ((num & 1) == 1)
            {
                curLen++;
            }
            else
            {
                preLen = ((num & 2) == 0) ? 0 : curLen; //判断下一比特位是否为0
                curLen = 0;
            }

            maxLen = max(maxLen, preLen + curLen + 1);
            num >>= 1;
        }

        return maxLen;
    }
};

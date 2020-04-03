#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumbers(vector<int> &nums)
    {
        int num = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            num ^= nums[i];
        }
        //转成最右边带1的数如010
        int count = num & (-num);
        //分成俩个数一个此位为0 一个此位为1的数进行 异或
        int num2 = 0, num1 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count & nums[i])
            {
                num1 ^= nums[i];
            }
            else
            {
                num2 ^= nums[i];
            }
        }
        return {num1, num2};
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int xornum = 0;
        for (auto num : nums)
            xornum ^= num;
        int b = (xornum == INT_MIN ? xornum : xornum & (-xornum));

        int type1 = 0;
        for (auto num : nums)
            if (num & b)
                type1 ^= num;
        return {type1, xornum ^ type1};
    }
};

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), [](const int &x, const int &y) {
            long sx = 10, sy = 10;
            while (sx <= x)
            {
                sx *= 10;
            }
            while (sy <= y)
            {
                sy *= 10;
            }
            return sy * x + y > sx * y + x;
        });
        if (nums[0] == 0)
        {
            return "0";
        }
        string ret;
        for (int &x : nums)
        {
            ret += to_string(x);
        }
        return ret;
    }
};

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minStartValue(vector<int> &nums)
    {
        int startVal = 1;
        if (nums[0] < 0)
            startVal -= nums[0];
        int temp = startVal;
        for (auto num : nums)
        {
            if (num < 0 && temp + num <= 0)
            {
                startVal += (1 - (temp + num));
                temp = 1;
            }
            else
                temp += num;
        }
        return startVal;
    }
};
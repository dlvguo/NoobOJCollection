#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        //注意0
        if (nums.size() == 0)
            return 0;
        int _max = 1, temp = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
                temp++;
            else
            {
                _max = max(_max, temp);
                temp = 1;
            }
        }
        _max = max(_max, temp);
        return _max;
    }
};
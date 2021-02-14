#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int _max = 0, temp = 0;
        for (int i = 0; i < nums.size();)
        {
            temp = 0;
            while (i < nums.size() && nums[i++])
            {
                temp++;
            }
            _max = max(_max, temp);
        }
        return _max;
    }
};
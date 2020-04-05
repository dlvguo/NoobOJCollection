#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int nowNum;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
            {
                nowNum = nums[i];
                count = 1;
                continue;
            }
            if (nowNum == nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return nowNum;
    }
};
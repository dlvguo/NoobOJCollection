#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int nowNum = nums[0], count = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nowNum == nums[i])
                count++;
            else
            {
                count--;
                if (count == 0)
                {
                    i++;
                    nowNum = nums[i];
                    count = 1;
                }
            }
        }
        return nowNum;
    }
};
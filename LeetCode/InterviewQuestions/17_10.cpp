#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int pn = 0, count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count > 0)
            {
                if (pn != nums[i])
                {
                    count--;
                }
                else
                {
                    count++;
                }
            }
            else
            {
                pn = nums[i];
                count = 1;
            }
        }
        if (!count)
            return -1;
        count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (pn == nums[i])
                count++;
        }
        return count > nums.size() / 2 ? pn : -1;
    }
};
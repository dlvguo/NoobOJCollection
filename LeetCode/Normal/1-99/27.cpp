#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int left = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
                left++;
            else
            {
                nums[i - left] = nums[i];
                count++;
            }
        }
        return count;
    }
};
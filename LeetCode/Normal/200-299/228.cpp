#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> vts;
        for (int i = 0; i < nums.size();)
        {
            int j = i + 1;
            while (j < nums.size() && nums[j] == nums[j - 1] + 1)
            {
                j++;
            }
            string s;
            if (i == j - 1)
            {
                s = to_string(nums[i]);
            }
            else
            {
                s = to_string(nums[i]) + "->" + to_string(nums[j - 1]);
            }
            vts.push_back(s);
            i = j;
        }
        return vts;
    }
};
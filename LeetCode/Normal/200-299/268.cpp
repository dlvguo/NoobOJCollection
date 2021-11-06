#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        vector<int> hs(nums.size() + 1, 0);
        for (auto num : nums)
            hs[num]++;
        for (int i = 0; i < hs.size(); i++)
        {
            if (!hs[i])
                return i;
        }

        return 0;
    }
};
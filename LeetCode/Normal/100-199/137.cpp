#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (int num : nums)
        {
            ++freq[num];
        }
        int ans = 0;
        for (auto [num, occ] : freq)
        {
            if (occ == 1)
            {
                ans = num;
                break;
            }
        }
        return ans;
    }
};

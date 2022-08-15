#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> pairSums(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        vector<vector<int>> res;
        while (l < r)
        {
            int temp = nums[l] + nums[r];
            if (temp == target)
            {
                res.push_back({nums[l++], nums[r--]});
            }
            else if (temp < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return res;
    }
};
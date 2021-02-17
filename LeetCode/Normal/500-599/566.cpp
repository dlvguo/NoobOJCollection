#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        int m = nums.size();
        int n = nums[0].size();
        if (m * n != r * c)
        {
            return nums;
        }

        vector<vector<int>> ans(r, vector<int>(c));
        for (int x = 0; x < m * n; ++x)
        {
            ans[x / c][x % c] = nums[x / n][x % n];
        }
        return ans;
    }
};

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> temp;
    vector<vector<int>> subsets(vector<int> &nums)
    {
        res.push_back(temp);
        dfs(0, nums);
        return res;
    }
    void dfs(int index, vector<int> &nums)
    {
        if (index >= nums.size())
            return;
        temp.push_back(nums[index]);
        res.push_back(temp);
        dfs(index + 1, nums);
        temp.pop_back();
        dfs(index + 1, nums);
    }
};
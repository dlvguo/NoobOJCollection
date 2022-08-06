#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> visit;
    vector<vector<int>> res;
    vector<int> temp;

    void dfs(int index, vector<int> &nums)
    {
        if (index == nums.size())
            return;
        for (int i = index; i < nums.size(); i++)
        {
            if (visit[i] || i && nums[i - 1] == nums[i] && !visit[i - 1])
                continue;
            visit[i] = 1;
            temp.push_back(nums[i]);
            res.push_back(temp);
            dfs(i + 1, nums);
            temp.pop_back();
            visit[i] = 0;
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        visit.resize(nums.size(), 0);
        res.push_back({});
        dfs(0, nums);
        return res;
    }
};
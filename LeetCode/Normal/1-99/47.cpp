#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int vis[15] = {0};
    vector<vector<int>> vts;
    vector<int> v;
    void dfs(vector<int> &nums)
    {
        if (v.size() == nums.size())
        {
            vts.push_back(v);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            //去重
            if (vis[i] || i > 0 && nums[i] == nums[i - 1] && vis[i - 1] == false)
                continue;

            vis[i] = 1;
            v.push_back(nums[i]);
            dfs(nums);
            vis[i] = 0;
            v.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        //注意排序才方便去重
        sort(nums.begin(), nums.end());
        dfs(nums);
        return vts;
    }
};

int main()
{
    vector<int> nums = {3, 3, 0, 3};
    Solution s;
    s.permuteUnique(nums);
}
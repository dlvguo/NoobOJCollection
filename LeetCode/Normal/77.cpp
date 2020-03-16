#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> vts;
    vector<bool> visit;
    void dfs(vector<int> nums, vector<int> &pointNums, int steps = 0)
    {
        if (steps == nums.size())
        {
            vts.push_back(pointNums);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (visit[i])
                continue;
            else
            {
                visit[i] = true;
                pointNums.push_back(nums[i]);
                dfs(nums, pointNums, steps + 1);
                visit[i] = false;
                pointNums.pop_back();
            }
        }
    }

    void dfsPutNums(int n, int nowNum, int k, vector<int> &nums)
    {
        //剪枝
        if (nowNum > n || (k - nums.size()) > n - nowNum + 1)
            return;
        //可放可不放
        nums.push_back(nowNum);
        if (nums.size() == k)
        {
            vector<int> pointNums;
            dfs(nums, pointNums);
        }
        else
            dfsPutNums(n, nowNum + 1, k, nums);
        nums.pop_back();
        dfsPutNums(n, nowNum + 1, k, nums);
    }

    vector<vector<int>> combine(int n, int k)
    {
        if (!n)
            return {};
        visit.resize(k, false);
        vector<int> nums;
        dfsPutNums(n, 1, k, nums);
        return vts;
    }
};
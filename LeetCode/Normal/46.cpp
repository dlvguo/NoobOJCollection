#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> vts;

void dfs(vector<int> nums, vector<bool> &visit, vector<int> &pointNums, int steps = 0)
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
            dfs(nums, visit, pointNums, steps + 1);
            visit[i] = false;
            pointNums.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<bool> visit(nums.size(), false);
    vector<int> pointNums;
    dfs(nums, visit, pointNums);
    return vts;
}
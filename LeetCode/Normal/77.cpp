#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> vts;

    void dfsPutNums(int n, int nowNum, int k, vector<int> &nums)
    {
        //剪枝
        if (nowNum > n || (k - nums.size()) > n - nowNum + 1)
            return;
        //可放可不放
        nums.push_back(nowNum);
        if (nums.size() == k)
        {
            vts.push_back(nums);
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
        vector<int> nums;
        dfsPutNums(n, 1, k, nums);
        return vts;
    }
};
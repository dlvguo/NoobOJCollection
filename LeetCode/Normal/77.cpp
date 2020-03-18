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
            return vts;
        vector<int> nums;
        dfsPutNums(n, 1, k, nums);
        return vts;
    }
};

int main()
{
    Solution s1;
    int n, k;
    cin >> n >> k;
    vector<vector<int>> vts = s1.combine(n, k);
    for (int i = 0; i < vts.size(); i++)
    {
        for (int j = 0; j < vts[i].size(); j++)
        {
            cout << vts[i][j];
        }
        cout << endl;
    }
}
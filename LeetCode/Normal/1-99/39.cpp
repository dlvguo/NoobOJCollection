#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> vts;
    vector<int> v;
    void dfs(vector<int> &candidates, int target, int index)
    {
        if (target == 0)
        {
            vts.push_back(v);
            return;
        }
        if (candidates.size() == index || candidates[index] > target)
            return;
        //从多往下
        for (int i = target / candidates[index]; i >= 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                v.push_back(candidates[index]);
            }
            dfs(candidates, target - i * candidates[index], index + 1);
            for (int j = 0; j < i; j++)
            {
                v.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return vts;
    }
};

int main()
{
}
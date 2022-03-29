#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:

    vector<int> temp;
    vector<vector<int>> res;

    int l, t;
    void dfs(int point, int index, vector<int> &candidates)
    {
        if (point == t)
        {
            res.push_back(temp);
            return;
        }
        for (int i = index; i <= l; i++)
        {
            if (point + candidates[i] > t)
                return;
            temp.push_back(candidates[i]);
            dfs(point + candidates[i], i + 1, candidates);
            temp.pop_back();
            //注意去重的方式在当前for！！！
            while (i < candidates.size() - 1 && candidates[i + 1] == candidates[i])
            {
                i++;
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        t = target;
        l = candidates.size() - 1;
        while (l >= 0 && candidates[l] > target)
        {
            l--;
        }
        if (l < 0)
            return res;
        dfs(0, 0, candidates);
        return res;
    }
};
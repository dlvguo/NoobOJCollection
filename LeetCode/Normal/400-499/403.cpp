#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<unordered_map<int, int>> rec;

    bool dfs(vector<int> &stones, int i, int lastDis)
    {
        if (i == stones.size() - 1)
        {
            return true;
        }
        if (rec[i].count(lastDis))
        {
            return rec[i][lastDis];
        }
        for (int curDis = lastDis - 1; curDis <= lastDis + 1; curDis++)
        {
            if (curDis > 0)
            {
                int j = lower_bound(stones.begin(), stones.end(), curDis + stones[i]) - stones.begin();
                if (j != stones.size() && stones[j] == curDis + stones[i] && dfs(stones, j, curDis))
                {
                    return rec[i][lastDis] = true;
                }
            }
        }
        return rec[i][lastDis] = false;
    }

    bool canCross(vector<int> &stones)
    {
        int n = stones.size();
        rec.resize(n);
        return dfs(stones, 0, 0);
    }
};

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        int n = T.size();
        vector<int> ans(n), next(101, INT_MAX);
        for (int i = n - 1; i >= 0; --i)
        {
            int warmerIndex = INT_MAX;
            for (int t = T[i] + 1; t <= 100; ++t)
            {
                warmerIndex = min(warmerIndex, next[t]);
            }
            if (warmerIndex != INT_MAX)
            {
                ans[i] = warmerIndex - i;
            }
            next[T[i]] = i;
        }
        return ans;
    }
};

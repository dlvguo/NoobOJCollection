#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> mp(n + 1, 0);
        unordered_set<int> uset;
        for (int i = 0; i < trust.size(); i++)
        {
            mp[trust[i][1]]++;
            uset.insert(trust[i][0]);
        }

        for (int i = 1; i <= n; i++)
        {
            if (mp[i] == n - 1 && uset.find(i) == uset.end())
            {
                return i;
            }
        }
        return -1;
    }
};
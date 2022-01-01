#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        vector<vector<int>> ans;
        if (original.size() != m * n)
        {
            return ans;
        }
        for (auto it = original.begin(); it != original.end(); it += n)
        {
            ans.emplace_back(it, it + n);
        }
        return ans;
    }
};
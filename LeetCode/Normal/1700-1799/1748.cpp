#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int sumOfUnique(vector<int> &nums)
    {
        unordered_map<int, int> umap;
        for (auto num : nums)
        {
            umap[num]++;
        }
        int res = 0;
        for (auto it : umap)
        {
            if (it.second == 1)
                res += it.first;
        }
        return res;
    }
};
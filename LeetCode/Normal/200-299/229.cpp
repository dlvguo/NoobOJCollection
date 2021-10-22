#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int tot = nums.size() / 3;
        vector<int> res;
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            umap[nums[i]]++;
        }
        for (auto m : umap)
        {
            if (m.second > tot)
                res.push_back(m.first);
        }
        return res;
    }
};
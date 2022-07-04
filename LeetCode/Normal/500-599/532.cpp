#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        unordered_set<int> visited;
        unordered_set<int> res;
        for (int num : nums)
        {
            if (visited.count(num - k))
            {
                res.emplace(num - k);
            }
            if (visited.count(num + k))
            {
                res.emplace(num);
            }
            visited.emplace(num);
        }
        return res.size();
    }
};
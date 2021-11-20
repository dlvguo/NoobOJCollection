#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        unordered_map<int, int> u_map;
        for (int i = 0; i < nums.size(); i++)
        {
            u_map[nums[i]]++;
        }
        int res = 0;
        for (auto u : u_map)
        {
            if (u_map.find(u.first - 1) != u_map.end())
            {
                int temp = u_map[u.first - 1] + u.second;
                res = max(res, temp);
            }
        }
        return res;
    }
};
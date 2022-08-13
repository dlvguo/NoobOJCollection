#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        unordered_map<int, vector<int>> ump;

        vector<vector<int>> res;

        for (int i = 0; i < groupSizes.size(); i++)
        {
            int num = groupSizes[i];
            ump[num].push_back(i);
            if (ump[num].size() == num)
            {
                res.push_back(ump[num]);
                ump.erase(num);
            }
        }
        return res;
    }
};
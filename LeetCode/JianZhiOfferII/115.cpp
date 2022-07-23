#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool sequenceReconstruction(vector<int> &nums, vector<vector<int>> &sequences)
    {
        queue<int> q;

        vector<int> dg(nums.size() + 1, 0);
        map<int, unordered_set<int>> mp;
        for (auto sq : sequences)
        {
            for (int i = 1; i < sq.size(); i++)
            {
                // 注意构建入度的时候 同个value的度不能相同
                if (mp[sq[i - 1]].find(sq[i]) == mp[sq[i - 1]].end())
                {
                    mp[sq[i - 1]].insert(sq[i]);
                    dg[sq[i]]++;
                }
            }
        }

        int i = 0;

        for (int t = 1; t < dg.size(); t++)
            if (!dg[t])
                q.push(t);
        while (q.size() == 1)
        {
            int temp = q.front();
            q.pop();
            if (temp != nums[i++])
                return false;
            for (auto num : mp[temp])
            {
                dg[num]--;
                if (!dg[num])
                {
                    q.push(num);
                }
            }
        }
        return i == nums.size();
    }
};
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool static cmp(const vector<int> v1, const vector<int> v2)
    {
        return v1[0] == v2[0] ? v1[1] > v2[1] : v1[0] < v2[0];
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back({intervals[0][0], intervals[0][1]});
        for (int i = 1; i < intervals.size(); i++)
        {
            // 说明在区间外
            if (intervals[i][0] > res.back()[1])
            {
                res.push_back({intervals[i][0], intervals[i][1]});
            }
            else
            {
                if (intervals[i][1] > res.back()[1])
                {
                    res[res.size() - 1][1] = intervals[i][1];
                }
            }
        }
        return res;
    }
};
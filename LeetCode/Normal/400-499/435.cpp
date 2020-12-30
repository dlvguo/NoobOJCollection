#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool cmp(vector<int> &n1, vector<int> &n2)
    {
        return n1[1] < n2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
            return 0;       
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 1, e = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= e)
            {
                e = intervals[i][1];
                ans++;
            }
        }
        return intervals.size() - ans;
    }
};
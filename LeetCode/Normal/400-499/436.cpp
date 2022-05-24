#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        vector<pair<int, int>> startIntervals;
        vector<pair<int, int>> endIntervals;
        int n = intervals.size();
        for (int i = 0; i < n; i++)
        {
            startIntervals.emplace_back(intervals[i][0], i);
            endIntervals.emplace_back(intervals[i][1], i);
        }
        sort(startIntervals.begin(), startIntervals.end());
        sort(endIntervals.begin(), endIntervals.end());

        vector<int> ans(n, -1);
        for (int i = 0, j = 0; i < n && j < n; i++)
        {
            while (j < n && endIntervals[i].first > startIntervals[j].first)
            {
                j++;
            }
            if (j < n)
            {
                ans[endIntervals[i].second] = startIntervals[j].second;
            }
        }
        return ans;
    }
};

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        if (timePoints.size() > 1440)
            return 0;
        priority_queue<int,vector<int>, greater<int>> pq;
        for (int i = 0; i < timePoints.size(); i++)
        {
            int num = ((timePoints[i][0] - '0') * 10 + (timePoints[i][1] - '0')) * 60 + ((timePoints[i][3] - '0') * 10 + (timePoints[i][4] - '0'));
            pq.push(num);
        }
        int first = pq.top(), pre = pq.top();
        int res = INT32_MAX;
        pq.pop();
        while (pq.size())
        {
            int n = pq.top();
            pq.pop();
            res = min(res, n - pre);
            pre = n;
        }
        res = min(res, first + 1440 - pre);
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> str = {"23:59", "00:00"};
    s.findMinDifference(str);
}
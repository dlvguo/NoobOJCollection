#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location)
    {
        int sameCnt = 0;
        vector<double> polarDegrees;
        for (auto &point : points)
        {
            if (point[0] == location[0] && point[1] == location[1])
            {
                sameCnt++;
                continue;
            }
            double degree = atan2(point[1] - location[1], point[0] - location[0]);
            polarDegrees.emplace_back(degree);
        }
        sort(polarDegrees.begin(), polarDegrees.end());

        int m = polarDegrees.size();
        for (int i = 0; i < m; ++i)
        {
            polarDegrees.emplace_back(polarDegrees[i] + 2 * M_PI);
        }

        int maxCnt = 0;
        double degree = angle * M_PI / 180;
        for (int i = 0; i < m; ++i)
        {
            auto it = upper_bound(polarDegrees.begin() + i, polarDegrees.end(), polarDegrees[i] + degree);
            int curr = it - polarDegrees.begin() - i;
            maxCnt = max(maxCnt, curr);
        }
        return maxCnt + sameCnt;
    }
};
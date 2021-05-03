#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        unordered_map<int, int> cnt;
        for (auto &widths : wall)
        {
            int n = widths.size();
            int sum = 0;
            for (int i = 0; i < n - 1; i++)
            {
                sum += widths[i];
                cnt[sum]++;
            }
        }
        int maxCnt = 0;
        for (auto &[_, c] : cnt)
        {
            maxCnt = max(maxCnt, c);
        }
        return wall.size() - maxCnt;
    }
};

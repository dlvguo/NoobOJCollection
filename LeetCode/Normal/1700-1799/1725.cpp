#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countGoodRectangles(vector<vector<int>> &rectangles)
    {
        int res = 0, maxLen = 0;
        for (auto &rectangle : rectangles)
        {
            int l = rectangle[0], w = rectangle[1];
            int k = min(l, w);
            if (k == maxLen)
            {
                ++res;
            }
            else if (k > maxLen)
            {
                res = 1;
                maxLen = k;
            }
        }
        return res;
    }
};
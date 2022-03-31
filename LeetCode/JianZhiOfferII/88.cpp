#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int two = cost[0], one = cost[1];
        for (int i = 2; i < cost.size(); i++)
        {
            int now = min(one, two)+cost[i];
            two = one;
            one = now;
        }
        return min(two, one);
    }
};
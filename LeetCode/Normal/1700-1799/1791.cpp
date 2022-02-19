#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        vector<int> dp(edges.size() + 2, 0);
        for (int i = 0; i < edges.size(); i++)
        {
            dp[edges[i][0]]++;
            dp[edges[i][1]]++;
        }
        for (int i = 0; i < dp.size(); i++)
        {
            if (dp[i] == edges.size())
                return i;
        }
        return -1;
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int pre1 = 0, pre2 = 0;
        //为了刷新
        for (int i = 2; i <= cost.size(); i++)
        {
            int t = min(cost[i - 1] + pre1, cost[i - 2] + pre2);
            pre2 = pre1;
            pre1 = t;
        }
        return pre1;
    }
};

int main()
{
    Solution s;
    vector<int> v = {
        0,
        1,
        1,
        0};
    cout << s.minCostClimbingStairs(v);
    system("pause");
}

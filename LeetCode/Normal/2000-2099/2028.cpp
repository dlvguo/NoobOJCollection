#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int res = 0;
        for (auto roll : rolls)
        {
            res += roll;
        }
        int point = (rolls.size() + n) * mean - res;
        if (point > n * 6 || point < n)
            return {};
        vector<int> ans(n, point / n);
        point %= n;
        int index = 0;
        while (point--)
        {
            ans[index++]++;
        }
        return ans;
    }
};
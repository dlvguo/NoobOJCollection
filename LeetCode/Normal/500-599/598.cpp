#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        int mina = m, minb = n;
        for (const auto &op : ops)
        {
            mina = min(mina, op[0]);
            minb = min(minb, op[1]);
        }
        return mina * minb;
    }
};
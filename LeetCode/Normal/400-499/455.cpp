#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0, sindex = 0;
        while (ans < g.size() && sindex < s.size())
        {
            if (g[ans] <= s[sindex++])
            {
                ans++;
            }
        }

        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int balancedStringSplit(string s)
    {
        int ans = 0, l = 0, r = 0;
        for (auto ch : s)
        {
            if (ch == 'L')
                l++;
            else
                r++;
            if (l == r)
                ans++;
        }
        return ans;
    }
};
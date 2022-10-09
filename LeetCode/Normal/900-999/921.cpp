#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int ans = 0;
        int leftCount = 0;
        for (auto &c : s)
        {
            if (c == '(')
            {
                leftCount++;
            }
            else
            {
                if (leftCount > 0)
                {
                    leftCount--;
                }
                else
                {
                    ans++;
                }
            }
        }
        ans += leftCount;
        return ans;
    }
};

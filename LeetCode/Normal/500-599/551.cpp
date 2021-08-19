#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkRecord(string s)
    {
        int an = 0;
        int lN = 0;
        for (auto c : s)
        {
            if (c == 'L')
            {
                lN++;
                if (lN == 3)
                    return false;
                continue;
            }
            else if (c == 'A')
            {
                an++;
                if (an == 2)
                    return false;
            }
            lN = 0;
        }
        return true;
    }
};
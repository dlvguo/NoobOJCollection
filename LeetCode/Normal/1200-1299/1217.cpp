#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {
        int even = 0, odd = 0;
        for (int pos : position)
        {
            if (pos % 2)
            {
                odd++;
            }
            else
            {
                even++;
            }
        }
        return min(odd, even);
    }
};

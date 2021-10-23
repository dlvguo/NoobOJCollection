#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        //
        int l, w;
        for (int i = 1; i <= area; i++)
        {
            if (area % i == 0)
            {
                l = i;
                w = area / i;
                if (l >= w)
                    break;
            }
        }
        return {l, w};
    }
};
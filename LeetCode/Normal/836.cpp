#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //注意边界取就好了 不要考虑可能的情况 否则太多
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        if (rec1[3] <= rec2[0] || rec1[3] <= rec2[1] || rec2[3] <= rec1[0] || rec2[3] <= rec1[1])
            return false;
        return true;
    }
};
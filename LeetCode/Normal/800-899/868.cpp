#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int binaryGap(int n)
    {

        int mask = 1;
        vector<int> temp;
        for (int i = 0; i < 31; i++)
        {
            if (mask & n)
                temp.push_back(i);
            mask = mask << 1;
        }
        int res = 0;
        for (int i = 1; i < temp.size(); i++)
            res = max(temp[i] - temp[i - 1], res);
        return res;
    }
};
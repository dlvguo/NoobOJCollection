#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int m = 0, res = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            m = max(m, arr[i]);
            if (m == i)
            {
                res++;
            }
        }
        return res;
    }
};

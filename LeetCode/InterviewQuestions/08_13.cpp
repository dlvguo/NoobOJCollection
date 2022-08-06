#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool cmp(vector<int> v1, vector<int> v2)
    {
        if (v1[0] == v2[0])
            return v1[1] < v2[1];
        return v1[0] < v2[0];
    }

    int pileBox(vector<vector<int>> &box)
    {
        sort(box.begin(), box.end());

        vector<int> f(box.size(), 0);

        int res = 0;

        for (int i = 0; i < box.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (box[i][0] > box[j][0] && box[i][1] > box[j][1] && box[i][2] > box[j][2])
                {
                    f[i] = max(f[i], f[j] + box[i][2]);
                }
            }
            if (f[i] == 0)
                f[i] = box[i][2];
            res = max(f[i], res);
        }

        return res;
    }
};
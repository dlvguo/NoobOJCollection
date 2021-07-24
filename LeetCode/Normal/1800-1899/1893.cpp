#include <bits/stdc++.h>
using namespace std;
// class Solution
// {
// public:
//     bool isCovered(vector<vector<int>> &ranges, int left, int right)
//     {
//         int vis[66] = {0};
//         for (auto r : ranges)
//         {
//             for (int i = r[0]; i <= r[1]; i++)
//             {
//                 vis[i] = 1;
//             }
//         }
//         for (int i = left; i <= right; i++)
//         {
//             if (!vis[i])
//                 return false;
//         }
//         return true;
//     }
// };

class Solution
{
public:
    bool isCovered(vector<vector<int>> &ranges, int left, int right)
    {
        vector<int> diff(55, 0);

        for (auto r : ranges)
        {
            diff[r[0]]++;
            diff[r[1] + 1]--;
        }
        for (int i = 1; i < 52; i++)
        {
            diff[i] += diff[i - 1];
        }

        for (int i = left; i <= right; i++)
        {
            if (diff[i] <= 0)
                return false;
        }
        return true;
    }
};

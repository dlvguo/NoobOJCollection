#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool static cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int ans = 0;

        for (int i = 0; i < boxTypes.size(); i++)
        {
            if (boxTypes[i][0] <= truckSize)
            {
                ans += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else
            {
                ans += truckSize * boxTypes[i][1];
                truckSize = 0;
            }
            if (!truckSize)
                break;
        }

        return ans;
    }
};
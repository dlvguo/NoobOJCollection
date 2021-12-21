#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        int ans = 0;
        sort(heaters.begin(), heaters.end());
        for (int house : houses)
        {
            int j = upper_bound(heaters.begin(), heaters.end(), house) - heaters.begin();
            int i = j - 1;
            int rightDistance = j >= heaters.size() ? INT_MAX : heaters[j] - house;
            int leftDistance = i < 0 ? INT_MAX : house - heaters[i];
            int curDistance = min(leftDistance, rightDistance);
            ans = max(ans, curDistance);
        }
        return ans;
    }
};

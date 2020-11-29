#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findBestValue(vector<int> &arr, int target)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> prefix(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            prefix[i] = prefix[i - 1] + arr[i - 1];
        }

        int r = *max_element(arr.begin(), arr.end());
        int ans = 0, diff = target;
        for (int i = 1; i <= r; ++i)
        {
            auto iter = lower_bound(arr.begin(), arr.end(), i);
            int cur = prefix[iter - arr.begin()] + (arr.end() - iter) * i;
            if (abs(cur - target) < diff)
            {
                ans = i;
                diff = abs(cur - target);
            }
        }
        return ans;
    }
};

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> cnt;
        for (int num : nums)
        {
            cnt[num]++;
        }
        sort(nums.begin(), nums.end(), [&](const int a, const int b)
             {
            if (cnt[a] != cnt[b]) {
                return cnt[a] < cnt[b];
            }
            return a > b; });
        return nums;
    }
};

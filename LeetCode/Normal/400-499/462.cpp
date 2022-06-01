#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ret = 0, x = nums[n / 2];
        for (int i = 0; i < n; i++) {
            ret += abs(nums[i] - x);
        }
        return ret;
    }
};


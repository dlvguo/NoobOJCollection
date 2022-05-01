#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int smallestRangeI(vector<int> &nums, int k)
    {
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());
        return maxNum - minNum <= 2 * k ? 0 : maxNum - minNum - 2 * k;
    }
};

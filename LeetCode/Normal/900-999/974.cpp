#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subarraysDivByK(vector<int> &A, int K)
    {
        int sum = 0;
        int ans = 0;
        vector<int> nums(K, 0);
        for (auto num : A)
        {
            sum = (sum + num) % K;
            sum = sum < 0 ? sum + K : sum;
            nums[sum] += 1;
        }
        for (auto num : nums)
        {
            if (num > 1)
                ans += num * (num - 1) / 2;
        }
        return ans + nums[0];
    }
};
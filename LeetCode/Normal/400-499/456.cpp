#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> candidate_k;
        candidate_k.push(nums[n - 1]);
        int max_k = INT_MIN;

        for (int i = n - 2; i >= 0; --i)
        {
            if (nums[i] < max_k)
            {
                return true;
            }
            while (!candidate_k.empty() && nums[i] > candidate_k.top())
            {
                max_k = candidate_k.top();
                candidate_k.pop();
            }
            if (nums[i] > max_k)
            {
                candidate_k.push(nums[i]);
            }
        }

        return false;
    }
};

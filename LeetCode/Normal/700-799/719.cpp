#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back();

        int ans = 0;

        while (left <= right)
        {
            int mid = (left + right) >> 1;
            int count = 0;
            for (int j = 1; j < nums.size(); j++)
            {
                int i = 0;
                while
            }
        }

        return ans;
    }
};
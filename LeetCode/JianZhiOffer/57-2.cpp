#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        vector<vector<int>> vs;
        if (target < 3)
            return vs;
        int left = 1, right = 2, sum = 3;
        while (right <= target / 2+1)
        {
            if (sum == target)
            {
                vector<int> v;
                v.resize(right - left + 1);
                for (int i = left; i <= right; i++)
                {
                    v[i - left] = i;
                }
                vs.push_back(v);
                right++;
                sum += right;
            }
            else if (sum > target)
            {
                sum -= left;
                left++;
            }
            else
            {
                right++;
                sum += right;
            }
        }
        return vs;
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int bestRotation(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> diffs(n);
        for (int i = 0; i < n; i++)
        {
            int low = (i + 1) % n;
            int high = (i - nums[i] + n + 1) % n;
            diffs[low]++;
            diffs[high]--;
            if (low >= high)
            {
                diffs[0]++;
            }
        }
        int bestIndex = 0;
        int maxScore = 0;
        int score = 0;
        for (int i = 0; i < n; i++)
        {
            score += diffs[i];
            if (score > maxScore)
            {
                bestIndex = i;
                maxScore = score;
            }
        }
        return bestIndex;
    }
};

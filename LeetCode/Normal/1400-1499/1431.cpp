#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int n = candies.size();
        int maxCandies = *max_element(candies.begin(), candies.end());
        vector<bool> ret;
        for (int i = 0; i < n; ++i)
        {
            ret.push_back(candies[i] + extraCandies >= maxCandies);
        }
        return ret;
    }
};
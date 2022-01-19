#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> _map;
        int i = 0;
        for (i = 0; i <= k && i < nums.size(); i++)
        {
            if (_map[nums[i]])
                return true;
            _map[nums[i]]++;
        }
        if (i <= k)
            return false;
        for (; i < nums.size(); i++)
        {
            _map[nums[i - k - 1]]--;
            if (_map[nums[i]])
                return true;
            _map[nums[i]]++;
        }
        return false;
    }
};
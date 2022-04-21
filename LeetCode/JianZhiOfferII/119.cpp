#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> uset;
        for (auto num : nums)
            uset.insert(num);
        int res = 0;
        while (uset.size())
        {
            int num = *uset.begin();
            uset.erase(num);
            int temp = 1;
            int left = num - 1;
            while (uset.find(left) != uset.end())
            {
                temp++;
                uset.erase(left--);
            }
            int right = num + 1;
            while (uset.find(right) != uset.end())
            {
                temp++;
                uset.erase(right++);
            }
            res = max(res, temp);
        }
        return res;
    }
};
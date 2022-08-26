#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        unordered_map<int, int> counts1, counts2;
        for (int num : target)
        {
            counts1[num]++;
        }
        for (int num : arr)
        {
            counts2[num]++;
        }
        if (counts1.size() != counts2.size())
        {
            return false;
        }
        for (auto &[key, value] : counts1)
        {
            if (!counts2.count(key) || counts2[key] != value)
            {
                return false;
            }
        }
        return true;
    }
};

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        map<vector<int>, int> mp;
        int ret = 0;
        for (auto domino : dominoes)
        {
            if (domino[0] > domino[1])
                swap(domino[0], domino[1]);
            mp[domino]++;
        }
        for (auto it : mp)
        {
            int n = it.second;
            if (n > 1)
                ret += n * (n - 1) / 2;
        }
        return ret;
    }
};
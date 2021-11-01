#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        unordered_set<int> hs;
        for (auto c : candyType)
        {
            hs.insert(c);
        }
        if (hs.size() < candyType.size() / 2)
            return hs.size();
        return candyType.size() / 2;
    }
};
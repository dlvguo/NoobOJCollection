#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string s)
    {
        vector<vector<int>> vts;
        for (int i = 0; i < s.size();)
        {
            int j = i + 1;
            for (; j < s.size() && s[j] == s[i]; j++)
            {
            }
            if (j - i > 2)
            {
                vts.push_back({i, j - 1});
            }
            i = j;
        }
        return vts;
    }
};
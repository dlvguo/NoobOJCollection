#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_set<string> uset;
        for (int i = 0; i < paths.size(); i++)
        {
            uset.insert(paths[i][0]);
        }
        for (int i = 0; i < paths.size(); i++)
        {
            if (uset.find(paths[i][1]) == uset.end())
                return paths[i][1];
        }
        return "";
    }
};
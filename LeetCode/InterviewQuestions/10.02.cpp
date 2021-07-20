#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> strMap;

        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (strMap.find(s) != strMap.end())
            {
                strMap[s].push_back(strs[i]);
            }
            else
            {
                vector<string> v;
                v.push_back(strs[i]);
                strMap[s] = v;
            }
        }
        vector<vector<string>> vts;

        for (auto &m : strMap)
        {
            vts.push_back(m.second);
        }

        return vts;
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mp;
        int length = s.length();
        for (auto &ch : s)
        {
            mp[ch]++;
        }
        vector<pair<char, int>> vec;
        for (auto &it : mp)
        {
            vec.emplace_back(it);
        }
        sort(vec.begin(), vec.end(), [](const pair<char, int> &a, const pair<char, int> &b)
             { return a.second > b.second; });
        string ret;
        for (auto &[ch, num] : vec)
        {
            for (int i = 0; i < num; i++)
            {
                ret.push_back(ch);
            }
        }
        return ret;
    }
};
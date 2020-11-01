#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<string, vector<string>> m;
        return helper(m, wordDict, s);
    }
    vector<string> helper(unordered_map<string, vector<string>> &m, vector<string> &wordDict, string s)
    {
        if (m.count(s))
            return m[s];
        if (s.empty())
            return {""};
        vector<string> res;
        for (auto word : wordDict)
        {
            if (s.substr(0, word.size()) != word)
                continue;
            vector<string> tmp = helper(m, wordDict, s.substr(word.size()));
            for (auto itm : tmp)
            {
                res.push_back(word + (itm.empty() ? "" : " " + itm));
            }
        }
        m[s] = res;
        return res;
    }
};
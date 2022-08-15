#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string strs[9] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    bool check(char ch, int index)
    {
        for (auto c : strs[index])
            if (ch == c)
                return true;
        return false;
    }

    vector<string> getValidT9Words(string num, vector<string> &words)
    {
        unordered_set<string> sset;
        for (auto word : words)
        {
            sset.emplace(word);
        }
        words.clear();

        for (auto str : sset)
        {
            words.push_back(str);
        }
        unordered_set<int> nset, n2set;
        for (int i = 0; i < words.size(); i++)
            nset.emplace(i);

        // 开始遍历
        for (int i = 0; i < num.size(); i++)
        {
            int index = num[i] - '2';

            if (i & 1)
            {
                for (auto n : n2set)
                {
                    if (check(words[n][i], index))
                    {
                        nset.emplace(n);
                    }
                }
                n2set.clear();
            }
            else
            {
                for (auto n : nset)
                {
                    if (check(words[n][i], index))
                    {
                        n2set.emplace(n);
                    }
                }
                nset.clear();
            }
        }
        vector<string> res;
        if (nset.size())
            for (auto n : nset)
                res.push_back(words[n]);
        else
            for (auto n : n2set)
                res.push_back(words[n]);
        return res;
    }
};
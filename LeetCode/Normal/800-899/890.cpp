#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string res = "";

    void m(string pattern)
    {
        int _map[26] = {0};
        int last = 1;
        for (int i = 0; i < pattern.size(); i++)
        {
            int index = pattern[i] - 'a';
            //第一次出现
            if (!_map[index])
            {
                res.push_back(last + '0');
                _map[index] = last++;
            }
            else
            {
                res.push_back(_map[index] + '0');
            }
        }
    }

    bool check(string word)
    {
        int _map[26] = {0};
        int last = 1;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            char ch;
            //第一次出现
            if (!_map[index])
            {
                ch = last + '0';

                _map[index] = last++;
            }
            else
            {
                ch = _map[index] + '0';
            }

            if (res[i] != ch)
                return false;
        }
        return true;
    }

    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> resv;
        m(pattern);
        for (auto word : words)
            if (check(word))
                resv.push_back(word);
        return resv;
    }
};
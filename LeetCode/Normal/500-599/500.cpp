#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        string str1 = "qwertyuiop", str2 = "asdfghjkl", str3 = "zxcvbnm";
        char set[27] = {0};
        for (auto ch : str1)
        {
            set[ch - 'a'] = 1;
        }
        for (auto ch : str2)
        {
            set[ch - 'a'] = 2;
        }
        for (auto ch : str3)
        {
            set[ch - 'a'] = 3;
        }
        vector<string> res;
        for (int i = 0; i < words.size(); i++)
        {
            int t;
            if (words[i].front() < 97)
                t = set[words[i].front() + 32 - 'a'];
            else
                t = set[words[i].front() - 'a'];
            for (int j = 1; j < words[i].size(); j++)
            {
                if (words[i][j] < 97 && set[words[i][j] + 32 - 'a'] != t || words[i][j] >= 97 && set[words[i][j] - 'a'] != t)
                {
                    t = 0;
                    break;
                }
            }
            if (t)
            {
                res.push_back(words[i]);
            }
        }
        return res;
    }
};
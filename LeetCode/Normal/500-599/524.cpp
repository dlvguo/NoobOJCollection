#include <bits/stdc++.h>
using namespace std;
//贪心排序
class Solution
{
public:
    static bool cmp(const string &s1, const string s2)
    {
        if (s1.size() < s2.size() || s1.size() == s2.size() && s1.compare(s2) > 0)
            return false;
        return true;
    }

    string findLongestWord(string s, vector<string> &dictionary)
    {
        string res = "";
        sort(dictionary.begin(), dictionary.end(), cmp);
        for (int i = 0; i < dictionary.size(); i++)
        {
            int l = 0, r = 0;
            while (l < dictionary[i].size() && r < s.size())
            {
                if (dictionary[i][l] == s[r++])
                {
                    l++;
                }
            }
            if (l == dictionary[i].size())
                return dictionary[i];
        }
        return res;
    }
};

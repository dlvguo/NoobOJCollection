#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> findOcurrences(string text, string first, string second)
    {
        vector<string> strs;
        for (int i = 0; i < text.size(); i++)
        {
            string res = "";
            while (i < text.size() && text[i] != ' ')
            {
                res.push_back(text[i++]);
            }
            strs.push_back(res);
        }
        vector<string> res;
        for (int i = 0; i < strs.size() - 2; i++)
        {
            if (!strs[i].compare(first) && !strs[i + 1].compare(second))
            {
                res.push_back(strs[i + 2]);
            }
        }
        return res;
    }
};
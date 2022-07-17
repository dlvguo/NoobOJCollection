#include <bits/stdc++.h>
using namespace std;
class WordFilter
{
private:
    unordered_map<string, int> dict;

public:
    WordFilter(vector<string> &words)
    {
        for (int i = 0; i < words.size(); i++)
        {
            int m = words[i].size();
            string word = words[i];
            for (int prefixLength = 1; prefixLength <= m; prefixLength++)
            {
                for (int suffixLength = 1; suffixLength <= m; suffixLength++)
                {
                    string key = word.substr(0, prefixLength) + '#' + word.substr(m - suffixLength);
                    dict[key] = i;
                }
            }
        }
    }

    int f(string pref, string suff)
    {
        string target = pref + '#' + suff;
        return dict.count(target) ? dict[target] : -1;
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool Judge(string word, vector<int> hashV)
    {
        for (int i = 0; i < word.size(); i++)
        {
            if (hashV[word[i] - 'a'])
            {
                hashV[word[i] - 'a']--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    int countCharacters(vector<string> &words, string chars)
    {
        vector<int> hashV(26, 0);
        for (int i = 0; i < chars.size(); i++)
        {
            hashV[chars[i] - 'a']++;
        }
        int count = 0;
        for (int i = 0; i < words.size(); i++)
        {
            if (Judge(words[i], hashV))
            {
                count += words[i].size();
            }
        }

        return count;
    }
};
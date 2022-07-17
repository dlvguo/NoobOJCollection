#include <bits/stdc++.h>
using namespace std;
class MagicDictionary
{
public:
    MagicDictionary() {}

    void buildDict(vector<string> dictionary)
    {
        words = dictionary;
    }

    bool search(string searchWord)
    {
        for (auto &&word : words)
        {
            if (word.size() != searchWord.size())
            {
                continue;
            }

            int diff = 0;
            for (int i = 0; i < word.size(); ++i)
            {
                if (word[i] != searchWord[i])
                {
                    ++diff;
                    if (diff > 1)
                    {
                        break;
                    }
                }
            }
            if (diff == 1)
            {
                return true;
            }
        }
        return false;
    }

private:
    vector<string> words;
};

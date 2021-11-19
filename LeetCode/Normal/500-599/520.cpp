#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int bigNum = 0;
        for (auto w : word)
        {
            if (w < 'a')
            {
                bigNum++;
            }
        }
        return bigNum == word.size() || bigNum == 1 && word[0] < 'a' || bigNum == 0;
    }
};
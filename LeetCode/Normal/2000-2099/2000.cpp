#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int i = 0;
        for (i = 0; i < word.size(); i++)
        {
            if (ch == word[i])
            {
                break;
            }
        }
        if (i == word.size())
            return word;
        // 0开始 需要到等于! 因为有奇数
        for (int j = 0; j <= i / 2; j++)
        {
            swap(word[j], word[i - j]);
        }
        return word;
    }
};
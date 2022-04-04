#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int indexs[26] = {0};
        for (int i = 0; i < letters.size(); i++)
        {
            indexs[letters[i] - 'a']++;
        }
        int num = (target - 'a' + 1) % 26;
        while (!indexs[num])
        {
            num++;
            num %= 26;
        }
        return num+'a';
    }
};
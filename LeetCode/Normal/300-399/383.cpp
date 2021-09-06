#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int hset[26] = {0};
        for (auto s : magazine)
        {
            hset[s - 'a']++;
        }
        for (auto s : ransomNote)
        {
            if (hset[s - 'a'])
                hset[s - 'a']--;
            else
                return false;
        }
        return true;
    }
};
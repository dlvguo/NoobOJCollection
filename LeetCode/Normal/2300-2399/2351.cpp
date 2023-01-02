#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char repeatedCharacter(string s)
    {
        int _m[26] = {0};
        for (auto ch : s)
        {
            _m[ch - 'a']++;
            if (_m[ch - 'a'] == 2)
                return ch;
        }

        return 'a';
    }
};
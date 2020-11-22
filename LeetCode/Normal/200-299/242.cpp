#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int dp[27] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            dp[s[i] - 'a']++;
        }
        for (int i = 0; i < t.length(); i++)
        {
            int index = t[i] - 'a';
            if (!dp[index])
                return false;
            dp[index]--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (dp[i])
                return false;
        }

        return true;
    }
};
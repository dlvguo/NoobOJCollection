#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int dp[26] = {0}, dp2[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            dp[s[i] - 'a']++;
            dp2[t[i] - 'a']++;
        }
        dp2[t.back() - 'a']++;
        for (int i = 0; i < 26; i++)
        {
            if (dp[i] != dp2[i])
                return 'a' + i;
        }
        return 'a';
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string sortString(string s)
    {
        string str;
        int dp[26] = {0};
        int totalCount = s.length();

        for (int i = 0; i < totalCount; i++)
        {
            dp[s[i] - 'a']++;
        }
        while (totalCount)
        {
            //从小到大
            for (int i = 0; i < 26; i++)
            {
                if (dp[i])
                {
                    totalCount--;
                    dp[i]--;
                    str.push_back(i + 'a');
                }
            }

            //从大到小
            for (int i = 25; i >= 0; i--)
            {
                if (dp[i])
                {
                    totalCount--;
                    dp[i]--;
                    str.push_back(i + 'a');
                }
            }
        }
        return str;
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dfs(const string &s, int l, int r, int k)
    {
        vector<int> cnt(26, 0);
        for (int i = l; i <= r; i++)
        {
            cnt[s[i] - 'a']++;
        }

        char split = 0;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] > 0 && cnt[i] < k)
            {
                split = i + 'a';
                break;
            }
        }
        if (split == 0)
        {
            return r - l + 1;
        }

        int i = l;
        int ret = 0;
        while (i <= r)
        {
            while (i <= r && s[i] == split)
            {
                i++;
            }
            if (i > r)
            {
                break;
            }
            int start = i;
            while (i <= r && s[i] != split)
            {
                i++;
            }

            int length = dfs(s, start, i - 1, k);
            ret = max(ret, length);
        }
        return ret;
    }

    int longestSubstring(string s, int k)
    {
        int n = s.length();
        return dfs(s, 0, n - 1, k);
    }
};

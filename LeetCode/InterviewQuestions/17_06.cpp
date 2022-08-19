#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string str;

    int dp[12][12] = {0};

    int dfs(int index, int cnt, bool limit)
    {
        if (str.size() == index)
            return cnt;
        if (!limit && dp[index][cnt])
            return dp[index][cnt];
        int res = 0, len = limit ? str[index] - '0' : 9;
        for (int i = 0; i <= len; i++)
            res += dfs(index + 1, cnt + (i == 2), limit && (i == len));
        if (!limit)
            dp[index][cnt] = res;
        return res;
    }

    int numberOf2sInRange(int n)
    {
        str = to_string(n);
        return dfs(0, 0, true);
    }
};

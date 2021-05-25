#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int strangePrinter(string s)
    {
        int n = s.length();
        vector<vector<int>> f(n, vector<int>(n));
        for (int i = n - 1; i >= 0; i--)
        {
            f[i][i] = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    f[i][j] = f[i][j - 1];
                }
                else
                {
                    int minn = INT_MAX;
                    for (int k = i; k < j; k++)
                    {
                        minn = min(minn, f[i][k] + f[k + 1][j]);
                    }
                    f[i][j] = minn;
                }
            }
        }
        return f[0][n - 1];
    }
};

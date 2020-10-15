#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> vec;
    int kInversePairs(int n, int k)
    {
        vec = vector<vector<int>>(n + 1, vector<int>(k + 1, 0));
        vec[0][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            vec[i][0] = 1;
            for (int j = 1; j <= k; ++j)
            {
                vec[i][j] = vec[i - 1][j] + vec[i][j - 1];
                if (vec[i][j] >= 1000000007) // 取模
                    vec[i][j] -= 1000000007;
                if (j >= i)
                {
                    vec[i][j] += 1000000007 - vec[i - 1][j - i];
                    if (vec[i][j] >= 1000000007) // 取模
                        vec[i][j] -= 1000000007;
                }
            }
        }
        return vec[n][k];
    }
};
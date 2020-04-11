#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //K 机会 N 楼层
    //状态转移方程：dp[k][step] = dp[k][step-1] + dp[k-1][step-1] + 1
    //dp内存的是k个鸡蛋下扔step次能确定的最大层数
    int superEggDrop(int K, int N)
    {
        vector<vector<int>> dp(K + 1, vector<int>(N + 1));
        for (int step = 1; step <= N; ++step)
        {
            dp[0][step] = 0;
            for (int k = 1; k <= K; ++k)
            {
                dp[k][step] = dp[k - 1][step - 1] + dp[k][step - 1] + 1;
                if (dp[k][step] >= N)
                    return step;
            }
        }
        return N;
    }
};
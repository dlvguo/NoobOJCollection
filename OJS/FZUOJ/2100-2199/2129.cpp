#include <iostream>
#include <string.h>
using namespace std;
typedef long long LL;

const int MAX = 1e6 + 5;
const int MOD = 1e9 + 7;

int nums[MAX];
int dp[MAX];
int _hash[MAX];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &nums[i]);
        }
        memset(_hash, 0, sizeof(_hash));
        for (int i = 1; i <= n; i++)
        {
            //不能加mod后在%mod,会超int
            dp[i] = dp[i - 1] * 2 % MOD;
            if (_hash[nums[i]])
            {
                dp[i] = (dp[i] - dp[_hash[nums[i]] - 1] + MOD) % MOD;
            }
            //每次只记录前一次出现的位置就行
            _hash[nums[i]] = i;
        }
        //空串计算两次，减一
        printf("%d\n", dp[n] - 1);
    }
    return 0;
}
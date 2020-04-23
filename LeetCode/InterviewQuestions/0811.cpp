#include <iostream>
using namespace std;

class Solution
{
public:
    int waysToChange(int n)
    {
        // (5x + 2y + z) * 5 + k = n
        // i * 5 + k = n (if i = 5x + 2y + z)
        // i = (n - k) / 5 = [0, n / 5]
        // 5x + 2y + z = i
        // y = (i - 5x - z) / 2 = [0, ([0, n / 5] - 5x) / 2]
        unsigned long long total = 0;
        int dp[5] = {0};
        for (int i = 0; i <= n / 5; i++)
        {
            total += dp[i % 5] += i / 2 + 1;
        }
        return total % 1000000007;
    }
};
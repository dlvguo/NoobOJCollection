#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    static constexpr array<int, 10> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    static constexpr int num_max = 30;
    static constexpr int mod = 1000000007;

public:
    int numberOfGoodSubsets(vector<int> &nums)
    {
        vector<int> freq(num_max + 1);
        for (int num : nums)
        {
            ++freq[num];
        }

        vector<int> f(1 << primes.size());
        f[0] = 1;
        for (int _ = 0; _ < freq[1]; ++_)
        {
            f[0] = f[0] * 2 % mod;
        }

        for (int i = 2; i <= num_max; ++i)
        {
            if (!freq[i])
            {
                continue;
            }

            // 检查 i 的每个质因数是否均不超过 1 个
            int subset = 0, x = i;
            bool check = true;
            for (int j = 0; j < primes.size(); ++j)
            {
                int prime = primes[j];
                if (x % (prime * prime) == 0)
                {
                    check = false;
                    break;
                }
                if (x % prime == 0)
                {
                    subset |= (1 << j);
                }
            }
            if (!check)
            {
                continue;
            }

            // 动态规划
            for (int mask = (1 << primes.size()) - 1; mask > 0; --mask)
            {
                if ((mask & subset) == subset)
                {
                    f[mask] = (f[mask] + static_cast<long long>(f[mask ^ subset]) * freq[i]) % mod;
                }
            }
        }

        int ans = 0;
        for (int mask = 1, mask_max = (1 << primes.size()); mask < mask_max; ++mask)
        {
            ans = (ans + f[mask]) % mod;
        }

        return ans;
    }
};

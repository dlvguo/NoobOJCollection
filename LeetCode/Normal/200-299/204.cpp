#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static const int MAX = 5e6 + 5;
    bool prime[MAX] = {true};

    int countPrimes(int n)
    {
        memset(prime, true, sizeof(prime));
        prime[0] = prime[1] = false;
        int ans = 0;
        for (int i = 2; i < n; i++)
        {
            if (prime[i])
            {
                for (int j = 2 * i; j < n; j += i)
                {
                    prime[j] = 0;
                }
                ans++;
            }
        }
        return ans;
    }
};
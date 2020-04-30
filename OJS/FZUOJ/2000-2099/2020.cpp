#include <iostream>
using namespace std;
typedef long long LL;

//注意一个定理
LL quickmod(LL a, LL b, LL m)
{
    LL ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a);
            if (ans >= m)
                ans %= m;
        }
        b >>= 1;
        a = a * a % m;
    }
    return ans;
}

LL C(LL n, LL m, LL p)
{
    if (m > n)
        return 0;
    LL ans = 1;
    for (int i = 1; i <= m; ++i)
    {
        LL a = (n - m + i) % p;
        LL b = i % p;
        ans = ans * a % p * quickmod(b, p - 2, p) % p;
    }
    return ans;
}
LL Lucas(LL n, LL m, LL p)
{
    if (m == 0)
        return 1;
    return Lucas(n / p, m / p, p) * C(n % p, m % p, p) % p;
}
int main()
{
    int T;
    LL n, m, p;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld%lld", &n, &m, &p);
        printf("%lld\n", Lucas(n, m, p));
    }
}

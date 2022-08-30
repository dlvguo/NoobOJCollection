#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL mod = 1e9 + 7;

int main()
{

    int n;
    cin >> n;
    if (n < 6)
        cout << 0 << endl;
    else if (n == 6)
        cout << 1 << endl;
    else
    {
        // 先计算C-4 代表总坑位
        LL temp = n - 4;
        // 考虑插槽为3的 会有redred重复
        LL fig = temp - 2, mask = 1;
        //代表总p排列数
        temp = temp * (temp - 1) / 2 % mod;
        // 26需要计算的数

        LL res = 1;
        LL j = 26;

        while (mask <= fig)
        {
            if (fig & mask)
            {
                res *= j;
                res %= mod;
            }
            mask <<= 1;
            j *= 26;
            j %= mod;
        }
        res = res * temp;
        LL pl = 0;
        // 计算会重复的数
        if (fig % 3 == 0)
        {
            // 代表3的个数
            int num = fig / 3;

            pl = (num + 2) * (num + 2) / 2 - 1;
            pl %= mod;
        }
        res -= pl;
        res %= mod;
        cout << res << endl;
    }
}
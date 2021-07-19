#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    int t;
    cin >> t;
    LL n, m;
    while (t--)
    {
        cin >> n >> m;
        LL total = n * m;
        if (m > 2)
        {
            LL rnum = m - 2;
            total -= rnum * n;
            m = 2;
        }
        if (n > 2)
        {
            LL ln = n - 2;
            total -= ln * m;
        }
        cout << total << endl;
    }
}
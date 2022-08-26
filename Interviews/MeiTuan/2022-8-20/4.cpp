#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;

// 编辑距离2

// a  1 2 3
// b  4 5 6 7

//   1 3
//   4
typedef long long LL;
LL figure(int as, int ae, int bs, int be)
{
    LL res = 0;

    while (as <= ae)
    {
        res += abs(a[as++] - b[bs++]);
    }

    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        b.push_back(temp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int as = 0, ae = a.size() - 1, bs = 0, be = b.size() - 1;
    if (a.size() > b.size())
    {

        // 要么消左边要么消右边
        int count = a.size() - b.size();
        LL res = LONG_LONG_MAX;
        // 开始消

        for (int i = 0; i <= count; i++)
        {
            LL temp = figure(as + i, ae - count + i, bs, be);
            for (int t = 0; t < as + i; t++)
            {
                temp += abs(a[t]);
            }
            for (int t = ae - count + i + 1; t <= ae; t++)
                temp += abs(a[t]);

            if (temp < res)
                res = temp;
        }
        cout << res << endl;
    }
    else if (a.size() < b.size())
    {
        // 要么消左边要么消右边
        int count = b.size() - a.size();
        LL res = LONG_LONG_MAX;
        // 开始消

        for (int i = 0; i <= count; i++)
        {
            LL temp = figure(as, ae, bs + i, be - count + i);
            for (int t = 0; t < bs + i; t++)
                temp += abs(b[t]);
            for (int t = be - count + i + 1; t <= be; t++)
                temp += abs(b[t]);
            if (temp < res)
                res = temp;
        }
        cout << res << endl;
    }
    else
    {
        LL res = figure(as, ae, bs, be);
        cout << res << endl;
    }
}
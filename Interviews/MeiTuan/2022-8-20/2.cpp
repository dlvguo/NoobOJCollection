#include <bits/stdc++.h>
using namespace std;

int check(int x, int y, int a, int b)
{
    return abs(x - a) + abs(y - b);
}

int main()
{
    int n;
    int z[3][2];
    int dis[3];
    cin >> n;
    for (int i = 0; i < 3; i++)
    {
        cin >> z[i][0] >> z[i][1];
    }

    for (int i = 0; i < 3; i++)
        cin >> dis[i];

    int x = 1, y = 1;

    for (int i = 1; i <= n; i++)
    {
        // 目标点
        int p = dis[0] - abs(z[0][0] - i);
        // 因为这个肯定大于0
        if (p < 0 || p > n)
            continue;
        // 小的那个值
        int t1 = z[0][1] - p;
        if (t1 > 0 && check(z[1][0], z[1][1], i, t1) == dis[1] && check(z[2][0], z[2][1], i, t1) == dis[2])
        {
            x = i;
            y = t1;
            break;
        }

        t1 = z[0][1] + p;
        if (t1 <= n && check(z[1][0], z[1][1], i, t1) == dis[1] && check(z[2][0], z[2][1], i, t1) == dis[2])
        {
            x = i;
            y = t1;
            break;
        }
    }

    cout << x << ' ' << y << endl;
}
#include <bits/stdc++.h>
using namespace std;

/**
 * 给2个数组
 * k = 2
 * 50 70 90
 * 90 80 100
 * 0.5*90+0.7*80+0.9*100=期望分数
 * 1*90+
 **/


int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(n), s(n);
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        p[i] = b;
    }

    double ans = 0;

    priority_queue<double, vector<double>, greater<double>> pq;

    for (int i = 0; i < n; i++)
    {

        ans += (1.0 * p[i] * s[i] / 100);

        double prove = (1.0 * (100 - p[i]) * s[i] / 100);
        if (pq.size() < m)
            pq.push(prove);
        else
        {
            if (prove > pq.top())
            {
                pq.pop();
                pq.push(prove);
            }
        }
    }

    while (pq.size())
    {
        ans += pq.top();
        pq.pop();
    }
    printf("%.2lf\n", ans);
}
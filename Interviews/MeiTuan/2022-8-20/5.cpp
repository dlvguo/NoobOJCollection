#include <bits/stdc++.h>
using namespace std;

/**
 * b是一堆钢板 1 2 3
 * a要放在b上面，a大于b才能放在b上面，求把这些b全压了最少的重量
 * b的重量 1 2 3
 * a的重量 2 3 4
 * 
 *  b a 
 *  b 重量 a>b[i]
 * a一堆材料 a[i]
**/
int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> b, a;
    for (int i = 0; i < n; i++)
    {

        int temp;
        cin >> temp;
        b.push_back(temp);
    }

    for (int i = 0; i < m; i++)
    {

        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long res = 0;
    int al = 0;

    for (int i = 0; i < b.size(); i++)
    {
        while (al < a.size() && a[al] < b[i])
            al++;
        if (al == a.size())
        {
            // 注意 cout！！！不能 return 靠 leetcode刷习惯了
            res = -1;
            break;
        }
        res += a[al];
    }
    cout << res << endl;
}

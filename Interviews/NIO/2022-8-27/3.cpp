#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    string res = "";
    if (n + m < 1e5)
    {
        for (int i = 1; i <= n; i++)
        {
            res.push_back('R');
        }
        res.push_back('P');
        for (int i = 1; i <= m; i++)
        {
            res.push_back('R');
        }
    }
    cout << res << endl;
}
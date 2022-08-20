#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    int n;
    cin >> n;
    cin >> a;
    cin >> b;
    string res = "";
    for (int i = 0; i < n; i++)
    {
        res.push_back(a[i]);
        res.push_back(b[i]);
    }
    cout << res << endl;
}

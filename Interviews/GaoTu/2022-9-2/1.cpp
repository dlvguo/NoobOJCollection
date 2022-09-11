#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string str = to_string(n);

    int st[10] = {0};
    int res = 0;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        int num = str[i] - '0';
        if (!st[num])
        {
            res = res * 10 + num;
            st[num] = 1;
        }
    }
    cout << res << endl;
}
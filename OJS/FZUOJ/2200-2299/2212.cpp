#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int t, n, m;
    int power[105];
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> power[i];
        }
        sort(power, power + n);
        int ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int need = 100 - power[i];
            if (need <= m)
            {
                ans++;
                m -= need;
            }
            else
            {
                break;
            }
        }
        cout << ans << endl;
    }
}
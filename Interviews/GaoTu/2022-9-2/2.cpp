#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b > c && abs(a - b) < c)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}

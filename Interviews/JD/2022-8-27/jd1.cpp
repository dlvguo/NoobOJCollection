#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    int n, k;
    cin >> n >> k;
    cin >> str;
    for (int i = 0; i < k; i++)
    {
        if (str[i] > 'Z')
        {
            str[i] -= 32;
        }
    }

    for (int i = k; i < str.size(); i++)
    {
        if (str[i] < 'a')
        {
            str[i] += 32;
        }
    }
    cout << str << endl;
}
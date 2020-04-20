#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;

vector<string> vts(10002);

int main()
{
    int t, n;
    string str;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        getchar();
        for (int i = 0; i < n; i++)
        {
            getline(cin, str);
            vts[i] = str;
        }
        sort(vts.begin(), vts.begin() + n);
        for (int i = 0; i < n; i++)
        {
            cout << vts[i];
        }
        cout << endl;
    }
}
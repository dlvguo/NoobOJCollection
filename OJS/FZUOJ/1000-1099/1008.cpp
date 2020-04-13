#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef long long ll;

int main()
{
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF)
    {
        map<string, ll> dict;
        while (m--)
        {
            ll t;
            string s;
            cin >> s >> t;
            dict.insert(pair<string, ll>(s, t));
        }
        string str;
        map<string, ll>::iterator iter;
        getchar();
        while (n--)
        {
            long long sum = 0;
            while (cin >> str, str != ".")
            {

                iter = dict.find(str);
                if (iter != dict.end())
                {
                    sum += iter->second;
                }
            }
            cout << sum << endl;
        }
    }
}
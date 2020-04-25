#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long LL;
int main()
{
    int t;
    cin >> t;
    LL a, b, x;
    for (int ans = 1; ans <= t; ans++)
    {
        int count = 0;
        cin >> a >> b;
        while (a > b)
        {
            //使他最大就是a=a/2+1;
            a = a / 2 + 1;
            count++;
        }
        printf("Case %d: %d\n", ans, count);
    }
}
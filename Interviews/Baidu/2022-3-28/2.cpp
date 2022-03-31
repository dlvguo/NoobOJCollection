#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int gcd(int a, int b)
{
    int num = a % b;
    return num ? gcd(b, num) : b;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        scanf("%d", &n);
        int ans = 1;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0 && gcd(n / i, i)==1)
            {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
}
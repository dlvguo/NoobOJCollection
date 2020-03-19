#include <iostream>
using namespace std;

int f[50005] = {0, 1};//有个规律 f[1]=1,f[2]=3 然后从i=1开始 f[1]-f[0]开始有 1 2 2 4 4 4 8 8 8 8 这样递增关系 同时注意俩个数%10000

int Figure(int n)
{
    if (f[n])
        return f[n];
    int count = 2, num = 2, nowCount = 2;

    for (int i = 2; i <= n; i++)
    {
        f[i] = (f[i - 1] + num) % 10000;
        nowCount--;
        if (!nowCount)
        {
            count++;
            nowCount = count;
            num *= 2;
            num %= 10000;
        }
    }
    return f[n];
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", Figure(n));
    }
}

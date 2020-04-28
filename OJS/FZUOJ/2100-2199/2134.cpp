#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
using namespace std;
#define INF 1e9

int in[205];

int FigureLowbit(int x)
{
    return x & (-x);
}
int FigureSum(int end)
{
    int sum = 0;
    while (end > 0)
    {
        sum += in[end];
        end -= FigureLowbit(end);
    }
    return sum;
}
void Plus(int pos, int num)
{
    while (pos <= 200)
    {
        in[pos] += num;
        pos += FigureLowbit(pos);
    }
}
int main()
{
    int T;
    int n;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        memset(in, 0, sizeof(in));
        int ans = 0;
        while (n--)
        {
            int u;
            scanf("%d", &u);
            ans += FigureSum(u - 1);
            Plus(u, 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}

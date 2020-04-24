#include <iostream>
using namespace std;

int main()
{
    int n;
    while (~scanf("%d", &n), n)
    {
        int vs[101] = {0}, x, v, sum = 0;
        while (n--)
        {
            scanf("%d%d", &x, &v);
            vs[v]++;
            for (int i = v + 1; i < 100; i++)
            {
                sum += vs[i];
                //%=确实快了很多
                if (sum >= 1000000)
                    sum %= 1000000;
            }
        }
        printf("%d\n", sum);
    }
}
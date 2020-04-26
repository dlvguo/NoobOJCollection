#include <iostream>
using namespace std;
int main()
{
    int t, m, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        m = n / 2;
        if (n % 2 != 0)
            printf("%d\n", m * (m + 1));
        else
            printf("%d\n", m * m);
    }
    return 0;
}

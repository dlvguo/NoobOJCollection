#include <iostream>
using namespace std;

int main()
{
    int x;
    int a, b, c, d;
    while (cin >> x)
    {
        while (x--)
        {
            cin >> a >> b >> c >> d;
            int s1 = (a - b) * c;
            int s2 = a * d;
            if (s1 > s2)
                printf("0\n");
            if (s1 == s2)
                printf("-1\n");
            if (s1 < s2)
                printf("1\n");
        }
    }
}
#include <cstdio>
#include <math.h>
const double esp = 1e-5;

int main()
{
    double L, n, C, r, d, s;
    double left, right;
    while (scanf("%lf%lf%lf", &L, &n, &C) != EOF)
    {
        if (L < 0 && n < 0 && C < 0)
            break;
        left = 0.0;
        right = 0.5 * L;
        s = (1 + n * C) * L;
        while (right - left > esp)
        {
            d = (left + right) / 2;
            r = d / 2 + L * L / 8 / d;
            if (s <= 2 * r * asin(L / (2 * r)))
                right = d;
            else
                left = d;
        }
        printf("%.3f\n", d);
    }
    return 0;
}
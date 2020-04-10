#include <iostream>
#include <math.h>
using namespace std;

const double PI = 3.141592654;
//公式 V=PI*（D*D*D-d*d*d）/6
int main()
{
    double D, d, v;
    while (cin >> D >> v, D || v)
    {
        d = pow(pow(D, 3) - v * 6 / PI, 1.0 / 3);
        printf("%.3lf\n", d);
    }
    return 0;
}
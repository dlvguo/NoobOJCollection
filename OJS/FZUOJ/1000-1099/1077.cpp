#include <iostream>
using namespace std;

const double PI = 3.14159265358;

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        double r, h;
        int n;
        cin >> n;
        bool flag = false;
        //暴力法 取0.01
        for (r = 0.01;; r += 0.01)
        {
            if (PI * r * r > 500)
                break;
            h = 1.0 * (1000 - (PI * r * r * 2)) / (2 * PI * r);
            if (PI * r * r * h >= n)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            printf("%.1lf\n", r);
        else
        {
            printf("NO\n");
        }
    }
}
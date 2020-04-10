#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        double sum = 1;
        for (int i = 2; i <= n; i++)
        {
            sum += 1.0 / i;
        }
        printf("%.12lf\n", sum);
    }
}
#include <iostream>
using namespace std;

int main()
{
    double x;
    while (cin >> x, x)
    {
        double sum = 0;
        int num = 0;
        while (sum < x)
        {
            num++;
            sum += 1.0 / (num + 1);
        }
        printf("%d cars(s)\n", num);
    }
}
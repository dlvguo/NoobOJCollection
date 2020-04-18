#include <iostream>
using namespace std;

int main()
{
    int c, n;
    cin >> c;
    while (c--)
    {
        int nums[102] = {0};
        cin >> n;
        int n, sum = 0, num;
        while (n--)
        {
            cin >> num;
            sum += num;
        }
        double av = (1.0 * sum) / n;
        if (av == (int)av)
        {
            num = av;
        }
        else
        {
            num = av + 1;
        }
        sum = 0;
        for (int i = num; i <= 100; i++)
        {
            sum += nums[i];
        }
        printf("%.3lf", 1.0 * sum / n);
    }
}
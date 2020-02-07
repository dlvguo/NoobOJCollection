#include <iostream>
using namespace std;

int reverse(int x)
{
    int max = 0x7fffffff, min = 0x80000000;
    long reverse = 0;
    while (x)
    {
        reverse = reverse * 10 + x % 10;
        x /= 10;
    }
    if (reverse > max || reverse < min)
        return 0;
    return reverse;
}

int main()
{
    cout << reverse(1534236469);
}
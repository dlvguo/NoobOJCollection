#include <iostream>
using namespace std;

/*
    思路：求出r1/2与r2、r1/2与r3、r2与r3的最大公约数
        1.如果r1/2与r2的最大公约数不等于r2与r3的最大公约数 或者r1/2与r3的最大公约数不等于r2与r3的公约数，说明倒液体的过程中无法凑出需要的等分液体
        2.根据规律可看出，如果公约数相等，那么r1/（r2与r3的最大公约数）-1就是倒液体的次数
*/

//最大公约数
int gcd(int x, int y)
{
    if (x % y == 0)
        return y;
    return gcd(y, x % y);
}

int main()
{
    int n, r1, r2, r3;

    cin >> n;
    while (n--)
    {
        cin >> r1 >> r2 >> r3;
        int r2r3gcd = r2 > r3 ? gcd(r2, r3) : gcd(r3, r2);
        int r1r2gcd = r1 / 2 > r2 ? gcd(r1 / 2, r2) : gcd(r2, r1 / 2);
        int r1r3gcd = r1 / 2 > r3 ? gcd(r1 / 2, r3) : gcd(r3, r1 / 2);

        if (r1r2gcd != r2r3gcd || r1r3gcd != r2r3gcd)
            cout << "no" << endl;
        else
        {
            cout << (r1 / r2r3gcd - 1) << endl;
        }
    }
}

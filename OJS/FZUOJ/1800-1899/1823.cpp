#include <iostream>
using namespace std;

int quickPow(int a, int b, int mod)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    //尽可能多的3
    int n;
    while (cin >> n)
    {
        if (n <= 4)
        {
            cout << n << endl;
        }
        else
        {
            int sNum = n / 3;
            int mod = n % 3;
            int res;
            if (mod == 0)
            {
                res = quickPow(3, sNum, 2009);
            }
            //为1就添加到4上面
            else if (mod == 1)
            {
                res = 4 * quickPow(3, sNum - 1, 2009) % 2009;
            }
            //否则就多一个2
            else
                res = 2 * quickPow(3, sNum, 2009) % 2009;
            cout << res << endl;
        }
    }
}
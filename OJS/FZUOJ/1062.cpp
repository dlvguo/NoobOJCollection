#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        //判断1的位置，在小于n的时候每次都是变成偶数，相当于乘以2，在大于n的时候就会变成奇数位置
        int temp = 2, ans = 1;
        while (temp != 1)
        {
            temp = temp <= n ? temp * 2 : (temp - n) * 2 - 1;
            ans++;
        }
        cout << ans << endl;
    }
}
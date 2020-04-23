#include <iostream>
using namespace std;

int main()
{
    int n, c, k;
    cin >> n;
    //找规律 只要乘积为偶数就能有回路 除非边为1
    while (n--)
    {
        cin >> c >> k;
        if (c * k % 2 == 0 && c != 1 && k != 1)
            cout << "Yes" << endl;
        else
        {
            cout << "No" << endl;
        }
    }
}
#include <iostream>
using namespace std;

//鸡兔同笼签到题
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int x1 = (b - 2 * a) / 2;
        cout << x1 << ' ' << a - x1 << endl;
    }
}
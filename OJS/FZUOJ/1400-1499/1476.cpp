#include <iostream>
using namespace std;

typedef long long LL;

int main()
{
    LL a, b;
    while (cin >> a >> b)
    {
        //注意一个公式
        cout << (a * b * (a + 1) * (b + 1) / 4) << endl;
    }
}
#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    //这是一道规律题
    while (T--)
    {
        long long n;
        cin >> n;
        if (n < 20150001)
            cout << n + 2014 << endl;
        else
            cout << 20152014 << endl;
    }
}
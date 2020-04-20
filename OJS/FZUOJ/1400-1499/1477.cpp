#include <iostream>
using namespace std;

char num[50];

void TraceBack(int n, int k)
{
    if (n)
    {
        TraceBack(n / k, k);
        cout << num[n % k];
    }
}

int main()
{
    int n, k;
    for (int i = 0; i < 10; i++)
    {
        num[i] = i + '0';
    }
    for (int i = 10; i < 36; i++)
    {
        num[i] = i - 10 + 'A';
    }

    while (cin >> n >> k)
    {
        //一般格式编辑器问题都对 就考虑是不是忽略了边界
        if (n == 0)
        {
            cout << 0;
        }
        TraceBack(n, k);
        cout << endl;
    }
}
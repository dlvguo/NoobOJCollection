#include <iostream>
#include <cstring>
using namespace std;

//硬币1 4 5 尽可能选择少的硬币凑满 注意加=号 跟完全背包问题一样
int main()
{
    int count = -1, five, four, one, n;
    cin >> n;
    for (int i = n / 5; i >= 0; i--)
    {
        for (int j = 0; j <= n / 4; j++)
        {
            int temp = i * 5 + j * 4;
            if (temp <= n)
            {
                int _count = i + j + (n - temp);
                if (count == -1 || _count <= count)
                {
                    count = _count;
                    five = i;
                    four = j;
                    one = n - temp;
                }
            }
            else
            {
                break;
            }
        }

        /* code */
    }
    cout << one << ',' << four << ',' << five << endl;
    system("pause");
}

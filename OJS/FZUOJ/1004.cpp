#include <iostream>
#include <algorithm>
using namespace std;

long long a[1010][1010] = {0};

int main()
{
    int r;
    while (cin >> r)
    {

        scanf("%d", &a[1][1]);
        for (int i = 2; i <= r; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                scanf("%d", &a[i][j]);
                a[i][j] += max(a[i - 1][j - 1], a[i - 1][j]);
            }
        }
        int _max = 0;
        for (int i = 1; i <= r; i++)
        {
            if (_max < a[r][i])
                _max = a[r][i];
        }
        cout << _max << endl;
    }
    //system("pause");
}
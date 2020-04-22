#include <iostream>
using namespace std;

int main()
{

    int m, n;
    char strs[101][20];
    while (cin >> n >> m)
    {
        //getchar(); 有时候忽略可不忽略都可
        for (int i = 0; i < n; i++)
        {
            cin >> strs[i];
        }
        int max = 0;
        for (int i = 0; i < m; i++)
        {
            int temp = 0;
            for (int j = 0; j < n; j++)
            {
                if (strs[j][i] == '0')
                    temp++;
            }
            max = temp > max ? temp : max;
        }
        cout << max + 1 << endl;
    }
}
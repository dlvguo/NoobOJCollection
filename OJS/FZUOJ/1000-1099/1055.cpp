#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    char str[5];
    while (cin >> n, n != -1)
    {
        bool define[26] = {1, 0};
        while (n--)
        {
            scanf("%s", str);
            if (define[str[2] - 'a'])
            {
                define[str[0] - 'a'] = true;
            }
            else
            {
                define[str[0] - 'a'] = false;//注意个大坑如果赋值的是未赋值的就又变成未赋值了
            }
        }
        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            if (define[i])
            {
                if (count)
                    cout << ' ';
                cout << (char)('a' + i);
                count++;
            }
        }
        if (!count)
            cout << "none";
        cout << endl;
    }
}
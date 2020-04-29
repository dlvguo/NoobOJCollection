#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int n;
    char s[202];
    while (~scanf("%s", s))
    {
        int len = strlen(s), ans = 0;
        scanf("%d", &n);
        char ch[202];
        while (n--)
        {
            scanf("%s", ch);
            int m = strlen(ch);
            //判断下长度不同直接去了
            if (len != m)
                continue;
            //暴力枚举
            for (int i = 0; i < len; i++)
            {
                int j = 0, k = i;
                while (j < m && s[k % len] == ch[j])
                {
                    k++;
                    j++;
                }
                if (j == m)
                {
                    ans++;
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

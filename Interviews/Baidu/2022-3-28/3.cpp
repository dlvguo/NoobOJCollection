#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    string str, temp;
    while (q--)
    {
        cin >> str;
        temp = str;
        int l = 0, r = str.size() - 1, res = 0;
        //先做c的
        while (l < r)
        {
            while (l < r && str[l] != 'C')
            {
                l++;
            }
            while (l < r && str[r] == 'C')
            {
                r--;
            }
            if (l < r)
            {
                if (l)
                {
                    reverse(str.begin(), str.begin() + l + 1);
                    res++;
                }
                reverse(str.begin(), str.begin() + r + 1);
                res++;
                l = 0;
            }
        }

        //先做b的
        //这时候r已经是最右非C的了
        l = 0;

        while (l < r && str[r] == 'C')
        {
            r--;
        }
        while (l < r)
        {
            //找到最左的a
            while (l < r && str[l] == 'A')
            {
                l++;
            }
            while (l < r && str[r] == 'B')
            {
                r--;
            }
            if (l < r)
            {
                if (l)
                {
                    reverse(str.begin(), str.begin() + l + 1);
                    res++;
                }
                reverse(str.begin(), str.begin() + r + 1);
                res++;
            }
        }

        int  _ans = res;
        str = temp;

        //先做固定小的
        l = 0, r = str.size() - 1, res = 0;
        //先做c的
        while (l < r)
        {
            while (l < r && str[l] != 'A')
            {
                l++;
            }
            while (l < r && str[r] == 'A')
            {
                r--;
            }
            if (l < r)
            {
                if (l)
                {
                    reverse(str.begin(), str.begin() + l + 1);
                    res++;
                }
                reverse(str.begin(), str.begin() + r + 1);
                res++;
                l = 0;
            }
        }

        //先做b的
        //这时候r已经是最右非C的了
        l = 0;

        while (l < r && str[r] == 'A')
        {
            r--;
        }
        while (l < r)
        {
            //找到最左的a
            while (l < r && str[l] == 'C')
            {
                l++;
            }
            while (l < r && str[r] == 'B')
            {
                r--;
            }
            if (l < r)
            {
                if (l)
                {
                    reverse(str.begin(), str.begin() + l + 1);
                    res++;
                }
                reverse(str.begin(), str.begin() + r + 1);
                res++;
            }
        }
        res=min(_ans,res+1);

        printf("%d\n", res);
    }
}
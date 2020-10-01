#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

typedef long long LL;

int find(LL k)
{
    //dig表示当前为几位数 ori表示当前位数的数字 orinum表示当前数字个数 count表示1-9位有9个数 10-99有90位数
    LL dig = 1, orinum = 1, ori = 1, count = 9;
    //计算区间落在具体数上
    while (k > orinum)
    {
        int temp = count;
        while (temp && k > orinum)
        {
            temp--;
            k -= orinum;
            orinum += dig;
            ori++;
        }
        if (temp)
        {
            break;
        }
        orinum++;
        dig++;
        count *= 10;
    }

    //找到这个数的第k位置
    if (k <= 9)
        return k;
    //如果是1位数 有9个 2位数有90个 确定具体数
    k -= 9;

    count = 90, dig = 2;
    while (k > count * dig)
    {
        k -= count * dig;
        count *= 10;
        dig++;
    }
    //确定具体的数
    int num = pow(10, dig - 1) + k / dig;
    if (k % dig == 0)
    {
        num--;
        return num % 10;
    }
    else
    {
        for (int i = 0; i < (dig - k % dig); i++)
        {
            num /= 10;
        }
        return num % 10;
    }
}

int main()
{
    int q;
    LL k;
    cin >> q;
    while (q--)
    {
        cin >> k;
        printf("%d\n", find(k));
    }
    //system("pause");
}
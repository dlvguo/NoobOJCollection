#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int num, pre, sum = 1, max = 1, pointNum;

        scanf("%d", &num);
        pre = num;
        pointNum = num;
        n--;
        while (n--)
        {
            scanf("%d", &num);
            if (num == pre)
                sum++;
            else
            {
                if (max < sum || max == sum && pointNum > pre)
                {
                    pointNum = pre;
                    max = sum;
                }
                pre = num;
                sum = 1;
            }
        }

        if (max < sum || max == sum && pointNum > pre)
        {
            pointNum = pre;
            max = sum;
        }
        printf("%d %d\n", pointNum, max);
    }
    //system("pause");
    return 0;
}
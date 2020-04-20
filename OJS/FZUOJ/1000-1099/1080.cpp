#include <iostream>
#include <stdio.h>
using namespace std;

/*  思路：找规律将矩阵回退，当下一个矩阵中含有负数的时候，说明当前矩阵为根矩阵：如n为奇数的时候
      1层:  0  6  0  8  0
      2层:  6  0  14 0  8 
      3层:  6  20 0  22 0
      因为最右边向右移会消除于是有：[2][4]=[3][5]  
      之后从右向左递推 [2][2]=[3][5]-[2][4]...
      之后从左向右递推 [2][3]=[3][2]-[3][1]  
*/

int main()
{
    int num[2][105] = {0};
    int n, t;
    scanf("%d", &n);
    while (n--)
    {
        int now = 0, pre = 1;
        bool tag = false;
        scanf("%d", &t);
        for (int i = 1; i <= t; i++)
        {
            scanf("%d", &num[now][i]);
        }
        //计算上一个数组含有负数的时候 说明当前数组为根
        while (!tag)
        {
            num[pre][t - 1] = num[now][t];
            for (int i = t - 3; i >= 1; i -= 2)
            {
                num[pre][i] = num[now][i + 1] - num[pre][i + 2];
                if (num[pre][i] < 0)
                {
                    tag = true;
                    break;
                }
            }
            if (tag)
                break;
            // 注意n为奇的时候 [x][1]要另外算 循环上述循环不会遍历到
            if (t % 2)
            {
                num[pre][1] = num[now][1] - num[pre][2];
                if (num[pre][1] < 0)
                {
                    break;
                }
            }
            for (int i = 3; i <= t; i += 2)
            {
                num[pre][i] = num[now][i - 1] - num[pre][i - 2];
                if (num[pre][i] < 0)
                {
                    tag = true;
                    break;
                }
            }
            if (tag)
                break;
            now = pre;
            pre = (pre + 1) % 2;
        }
        printf("%d", num[now][1]);
        for (int i = 2; i <= t; i++)
        {
            printf(" %d", num[now][i]);
        }
        cout << endl;
    }
}
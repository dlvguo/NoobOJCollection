#include <iostream>
#include <algorithm>
using namespace std;

/*
    迭代变量缩小内存
*/

typedef long long LL;

int nums[1000005];

int main()
{
    int n, t, m;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        LL lastSum = 0, preSum = 0;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", &nums[i]);
            lastSum += nums[i];
        }
        LL maxNum = lastSum, temp = lastSum;
        for (int i = m + 1; i <= n; i++)
        {
            scanf("%d", &nums[i]);
            lastSum += nums[i];
            preSum += nums[i - m];
            temp = max(temp + nums[i], lastSum - preSum);
            if (maxNum < temp)
                maxNum = temp;
        }
        printf("%I64d\n", maxNum);
    }
}

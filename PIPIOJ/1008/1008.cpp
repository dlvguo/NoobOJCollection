#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long ll;
int arr[100001], dp[100001];

bool Max(int a, int b)
{
    return a > b;
}

int main()
{
    int k;
    while (scanf("%d", &k) != EOF)
    {
        int start = 0, end = 0;
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &arr[i]);
        }
        ll max = 0;
        dp[0] = arr[0];
        int temp = 0;
        for (int i = 1; i < k; i++)
        {
            /*考虑自身为序列 后面会出现更大值 用temp暂存索引
              若序列增加超过max时 开始索引为temp  
            */
            if (Max(arr[i], dp[i - 1] + arr[i]))
            {
                if (max < arr[i])
                {
                    max = arr[i];
                    start = i;
                    end = i;
                }
                temp=i;
                dp[i] = arr[i];
            }
            else
            {
                dp[i] = dp[i - 1] + arr[i];
                if (max < dp[i])
                {
                    start=temp;
                    max = dp[i];
                    end = i;
                }
            }
        }
        if (max < 0)
        {
            start = end = max = 0;
        }
        printf("%ld %d %d\n", max, start, end);
    }
}
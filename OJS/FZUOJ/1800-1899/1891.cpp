#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int nums[50005];

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &nums[i]);
        }
        sort(nums, nums + n);
        for (int i = 2; i < n; i += 2)
        {
            swap(nums[i], nums[i - 1]);
        }

        printf("%d", nums[0]);

        for (int i = 1; i < n; i++)
        {
            printf(" %d", nums[i]);
        }
        printf("\n");
    }
}
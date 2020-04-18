#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long LL;

LL nums[100005];

long long _fabs(LL a, LL b)
{
    LL c = a - b;
    if (c > 0)
        return c;
    return -c;
}

//真TM难受 VC++可以用 lld 不然就是%I64d
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &nums[i]);
        }
        sort(nums, nums + n);
        LL _min = -1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1])
            {
                LL temp = _fabs(nums[i - 1], nums[i]);
                if (_min == -1)
                {
                    _min = temp;
                }
                else
                {
                    if (temp < _min)
                        _min = temp;
                }
            }
        }
        if (_min == -1)
            if (nums[0] < 0)
                _min = -nums[0];
            else
            {
                _min = nums[0];
            }

        printf("%lld\n", _min);
    }
}

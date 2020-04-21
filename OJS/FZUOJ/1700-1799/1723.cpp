#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

LL nums[1000005];

int main()
{
	//进行位计算即可
	int t, N;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &N);
		LL res = 0;
		//进行异或找出有
		for (int i = 0; i < N; i++)
		{
			scanf("%lld", &nums[i]);
			res ^= nums[i];
		}
		//找到res第一个为1的位置
		int k = 0;
		while (res)
		{
			if (res & 1)
				break;
			k++;
			res = res >> 1;
		}
		LL a = 0, b = 0;
		for (int i = 0; i < N; i++)
		{
			if ((nums[i] >> k) & 1) {
				a ^= nums[i];
			}
			else {
				b ^= nums[i];
			}
		}
		if (a < b)
			printf("%lld %lld\n", a, b);
		else
		{
			printf("%lld %lld\n", b, a);
		}
	}
}

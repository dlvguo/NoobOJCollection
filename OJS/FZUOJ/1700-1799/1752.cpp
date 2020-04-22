#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long LL;

/*
    这道题有个大坑 如果直用快速幂 LL会爆 必须配合快速乘 其中快速乘如果%=还是会超时 使用-=会快点

    思路：快速幂+快速乘
*/

//快速乘
LL quickMul(LL a, LL b, LL mod) {
	LL res = 0;
	while (b)
	{
		if (b & 1) {
			res += a;
			//注意%= 还得用快速求余  于是干脆用-=
			if (res >= mod)
				res -= mod; //大于减mod
		}
		a <<= 1;
		if (a >= mod)
			a -= mod;
		b >>= 1;
	}
	return res;
}

//快速幂
LL quickPow(LL a, LL b, LL mod)
{
	LL res = 1;
	a %= mod;
	while (b)
	{
		if (b & 1) {
			res = quickMul(res, b, mod);
		}
		b >>= 1;
		a = quickMul(a, a, mod);
	}
	return res;
}

int main()
{
	LL a, b, c, res;
	while (~scanf("%I64d%I64d%I64d", &a, &b, &c))
	{
		//注意快速幂 以及LL的时候快速乘
		a %= c;
		res = 1;
		while (b)
		{
			if (b & 1)
				res = quickMul(res, a, c);
			b = b >> 1;
			a = quickMul(a, a, c);
		}
		printf("%I64d\n", res);
	}
}
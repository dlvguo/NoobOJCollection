#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

/* 矩阵快速幂问题,重点是找到矩阵
	Sn=Sn-1+f(n)=Sn-1+3*f(n-1)+2*f(n-2)+7*f(n-3)
	Base:Sn		| 1 1 0 0 | Sn-1
		f(n+1) 	| 0	3 2 7 | f(n)
		f(n)	| 0 1 0 0 | f(n-1)
		f(n-1)	| 0	0 0 1 | f(n-2)

	Ori:S2		| 4 0 0 0 | 
		f(2) 	| 5	0 0 0 | 
		f(1)	| 3 0 0 0 | 
		f(0)	| 1	0 0 0 | 
*/
struct Matrix
{
	int m[5][5];

	Matrix()
	{
		memset(m, 0, sizeof(m));
	}

	//初始化特征矩阵
	void init()
	{
		m[1][1] = 1;
		m[1][2] = 1;
		m[2][2] = 3;
		m[2][3] = 2;
		m[2][4] = 7;
		m[3][2] = 1;
		m[4][3] = 1;
	}

	//单位化
	void unit()
	{
		for (int i = 1; i <= 4; i++)
		{
			m[i][i] = 1;
		}
	}
};

//矩阵相乘
Matrix mul(Matrix a, Matrix b)
{
	Matrix c;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 1; k <= 4; k++)
			{
				c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % 2009;
			}
		}
	}
	return c;
}

//计算矩阵n次方
Matrix pow(int n)
{
	Matrix res;
	Matrix mt;
	mt.init();
	//化成单位矩阵
	res.unit();

	while (n)
	{
		if (n & 1)
			res = mul(res, mt);
		mt = mul(mt, mt);
		n = n >> 1;
	}
	return res;
}

int main()
{

	int m, n, c = 1, ans;
	cin >> m;
	//初始矩阵
	Matrix oriM;
	oriM.m[1][1] = 4;
	oriM.m[2][1] = 5;
	oriM.m[3][1] = 3;
	oriM.m[4][1] = 1;
	while (m--)
	{
		cin >> n;
		if (n == 0)
		{
			ans = 1;
		}
		else
		{
			Matrix p = mul(pow(n - 1), oriM);
			ans = p.m[1][1];
		}
		printf("Case %d: %d\n", c++, ans);
	}
}
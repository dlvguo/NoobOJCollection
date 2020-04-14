#include <iostream>
#include <math.h>
using namespace std;
typedef long long LL;

int main()
{
	//打表下计算下每位数有多少个正常数字 比如10有8个 100内有64个 1000内有512个 因为2^64次方<10^20 因此计算19个即可
	LL table[25] = {1, 8};
	for (int i = 2; i < 20; i++)
	{
		table[i] = table[i - 1] * 8;
	}
	string str;
	while (cin >> str)
	{
		LL sum = 0;
		//从最大数计算 如22312=2*10000（8^4） +2312
		for (int i = 0, len = str.size() - 1; i < str.size(); i++, len--)
		{
			int n = str[i] - '0'; //获取数字
			int t = n;
			//n不为0的情况
			if (n)
			{
				//去除包含3和6的数
				if (n > 6)
				{
					n -= 2;
				}
				else if (n > 3)
				{
					n -= 1;
				}
				sum += table[len] * n;
				//如果此时数字为6或者3的话需要跳出 如6532=6000+532 因为最大位为6 剩下的后面数字无需计算
				if (t == 6 || t == 3)
				{
					sum--;
					break;
				}
			}
		}
		cout << sum << endl;
	}
}


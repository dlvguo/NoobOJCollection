#include <iostream>
#include <math.h>
using namespace std;
typedef long long LL;

// int main()
// {
// 	//改下了 可能爆了
// 	LL num = 10, table[25] = {1, 8};
// 	for (int i = 2; i < 20; i++)
// 	{
// 		table[i] = table[i - 1] * 8;
// 		num *= 10;
// 	}
// 	////可能是有超界的问题
// 	//for (int j = 19; j >= 1; j--)
// 	//{
// 	//	table[j] = num - table[j];
// 	//	num /= 10;
// 	//}
// 	string str;
// 	while (cin >> str)
// 	{
// 		LL sum = 0;
// 		//num = pow(10, str.size() - 1);
// 		for (int i = 0, len = str.size() - 1; i < str.size(); i++, len--)
// 		{

// 			int n = str[i] - '0'; //获取数字
// 			if (n)
// 			{
// 				if (n > 5)
// 				{
// 					n -= 2;
// 				}
// 				else if (n > 2)
// 				{
// 					n -= 1;
// 				}
// 				sum += table[len] * n;
// 			}
// 			//num /= 10;
// 		}
// 		cout << sum << endl;
// 	}
// }

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <math.h>

#define le 60

long long n;

long long d[le];

char s[le];

int main(void)
{

	int k, i, m;

	long long ans;

	while (scanf("%s", &s) != EOF)
	{

		ans = k = 0;

		m = (int)strlen(s);

		for (i = m - 1; i >= 0; i--)

			d[k++] = s[i] - '0';

		for (i = k - 1; i >= 0; i--)
		{

			if (d[i] <= 3)
			{

				ans += d[i] * (long long)pow(8., i);

				if (d[i] == 3)
				{

					ans--;

					break;
				}
			}

			else if (d[i] >= 4 && d[i] <= 6)
			{
				ans += (d[i] - 1) * (long long)pow(8., i);
				if (d[i] == 6)
				{
					ans--;
					break;
				}
			}
			else
				ans += (d[i] - 2) * (long long)pow(8., i);
		}

		printf("%lld\n", ans);
	}

	return 0;
}

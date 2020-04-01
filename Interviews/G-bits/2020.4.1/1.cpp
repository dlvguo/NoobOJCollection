#include <iostream>
#include<math.h>
using namespace std;

bool Judge(long long n) {
	//素数是用等号啊FUCK 
 	for (int i = 2; i <= sqrt(n); i++)
 	{
 		if (n % i == 0)
 			return false;
 	}
 	return true;
}
 
//给出一个1<n<100000，求绝对值最近的素数

int main() {
 	long long  n;
 	cin >> n;
 	long long pre = -1, next = -1;
 	if (n % 2 == 0) {
 		pre = n - 1;
 		next = n + 1;
 	}
 	else {
 		pre = n - 2;
 		next = n + 2;
 	}
 	while (pre > 1 && Judge(pre) == false)
 	{
 		pre -= 2;
 	}
 	while (Judge(next) == false)
 	{
 		next += 2;
 	}
 	if (pre < 2 || (next - n) < (n - pre))
 		cout << next << endl;
 	else
 		cout << pre << endl;
}
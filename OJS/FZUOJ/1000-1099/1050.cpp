#include <iostream>
#include <math.h>
#include <iostream>
using namespace std;

#define N 1000005

int dp[N] = {1};
//使用LOG10累加即可 应该数学关系
void Init()
{
    double sum = 0;
    for (int i = 1; i < N; i++)
    {
        sum += log10((double)i);
        dp[i] = (int)sum;
    }
}

int main()
{
    Init();
    int n;
    while (cin >> n)
    {
        cout << dp[n] + 1 << endl;
    }
}
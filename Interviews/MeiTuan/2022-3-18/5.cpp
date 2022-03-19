#include <iostream>
using namespace std;

typedef long long LL;

int nums[4] = {1, 0, 2};

int dfs(LL num, LL k)
{
    if (num == 1)
        return 0;
    // k=k%num;

    // 在第一块
    if (num / 3 >= k)
    {
        return 1 + dfs(num / 3, k);
    }
    else if (num / 3 * 2 >= k)
        return dfs(num / 3, k - num / 3);

    else
        return 2 + dfs(num / 3, k - num / 3 * 2);
}

int main()
{
    LL n, k, num = 1;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        num *= 3;
    }
    cout << dfs(num, k) << endl;
}
#include <bits/stdc++.h>
using namespace std;

int res = 0;
vector<int> deep;

const int DEEPMAX = 1e4 + 1;

void dfs(int L, int R)
{

    if (L > R)
        return;
    // 寻找里面最小值
    int deepmin = DEEPMAX;
    for (int i = L; i <= R; i++)
        deepmin = min(deep[i], deepmin);
    res += deepmin;
    int pre = L;
    for (int i = L; i <= R; i++)
    {
        deep[i] -= deepmin;
        // 说明为0则
        if (!deep[i])
        {
            dfs(pre, i - 1);
            pre = i + 1;
        }
    }
    dfs(pre, R);
}

int main()
{

    int n;
    cin >> n;
    // 代表下标为0的set
    set<int> dset;
    while (n--)
    {
        int num;
        cin >> num;
        deep.push_back(num);
        /* code */
    }

    int pre = 0;
    for (int i = 0; i <= deep.size() - 1; i++)
    {
        // 说明为0则
        if (!deep[i])
        {
            dfs(pre, i - 1);
            pre = i + 1;
        }
    }
    dfs(pre, deep.size() - 1);
    cout << res << endl;
}
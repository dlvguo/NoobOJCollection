#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &X, vector<int> &Y, int W)
{
    // 排序
    sort(X.begin(), X.end());
    int ans = 1, start = X[0];
    // 在范围内计算如果不满足则 压路机+1
    for (int i = 0; i < X.size(); i++)
    {
        if (start + W < X[i])
        {
            ans++;
            start = X[i];
        }
    }

    return ans;
}

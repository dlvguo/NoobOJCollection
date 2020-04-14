#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int count = 0;
    long long point = 0;
    bool visit[10] = {false};

    void dfs(int index, int n, int &k)
    {
        if (index == n)
        {
            if (!k)
                return;
            k--;
            return;
        }
        if (!k)
            return;
        for (int i = 1; i <= n; i++)
        {
            if (visit[i])
                continue;
            point = point * 10 + i;
            visit[i] = true;
            dfs(index + 1, n, k);
            if (!k)
                return;
            visit[i] = false;
            point /= 10;
        }
    }

    string getPermutation(int n, int k)
    {
        dfs(0, n, k);
        return to_string(point);
    }
};
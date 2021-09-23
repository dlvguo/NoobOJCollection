#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> vts;
    vector<string> v;

    //左斜线 r-i为固定值 右斜线r+i为固定值 大小为2*n注意映射
    int row[9] = {0}, zx[20] = {0}, yx[20] = {0};

    void dfs(int r, int n)
    {
        if (r == n)
        {
            vts.push_back(v);
            return;
        }
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            if (row[i] || zx[r - i + 9] || yx[r + i])
                continue;
            s[i] = 'Q';
            row[i] = zx[r - i + 9] = yx[r + i] = 1;
            v.push_back(s);
            dfs(r + 1, n);
            v.pop_back();
            row[i] = zx[r - i + 9] = yx[r + i] = 0;
            s[i] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        dfs(0, n);
        return vts;
    }
};
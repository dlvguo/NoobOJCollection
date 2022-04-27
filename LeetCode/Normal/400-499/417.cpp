#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // P 用于记录从太平洋出发所能达到的点
    // A 用于记录从大西洋出发所能达到的点
    vector<vector<int>> P, A, ans;
    int n, m;
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &M)
    {
        n = M.size(), m = M[0].size();
        P = A = vector<vector<int>>(n, vector<int>(m, 0));
        //左右两边加上下两边出发深搜
        for (int i = 0; i < n; ++i)
            dfs(M, P, i, 0), dfs(M, A, i, m - 1);
        for (int j = 0; j < m; ++j)
            dfs(M, P, 0, j), dfs(M, A, n - 1, j);
        return ans;
    }
    // 这里的 visited 是用引入的办法传参，实际上代表 P, A
    void dfs(vector<vector<int>> &M, vector<vector<int>> &visited, int i, int j)
    {
        // 如果一个点我们已经遍历过便返回
        if (visited[i][j])
            return;
        visited[i][j] = 1;

        // 每遍历完一个点后检查这个点是否能从 P 和 A 达到，见 P，A 定义
        // 如果可以则加入答案 matrix
        if (P[i][j] && A[i][j])
            ans.push_back({i, j});

        //上下左右深搜
        if (i - 1 >= 0 && M[i - 1][j] >= M[i][j])
            dfs(M, visited, i - 1, j);
        if (i + 1 < n && M[i + 1][j] >= M[i][j])
            dfs(M, visited, i + 1, j);
        if (j - 1 >= 0 && M[i][j - 1] >= M[i][j])
            dfs(M, visited, i, j - 1);
        if (j + 1 < m && M[i][j + 1] >= M[i][j])
            dfs(M, visited, i, j + 1);
    }
};

#include <bits/stdc++.h>
using namespace std;

/*N皇后问题有个计算优化思路
  左对角线 row-lie=n 这个n对于同个对角线的值相同 
  右对角线 row+lie=n 这个n对于同个对角线的值相同 
  正对角线用数组列下标映射即可
*/
class Solution
{
public:
    int ans = 0;
    //正对角线
    int visit[60] = {0};
    //左对角线
    int visit2[60] = {0};
    //右对角线
    int visit3[60] = {0};
    int totalNQueens(int n)
    {
        dfs(0, n);
        return ans;
    }
    void dfs(int row, int n)
    {
        if (row >= n)
        {
            ans++;
            return;
        }
        for (int i = 0; i < n; i++)
        {
            //i-row+n 避免负数
            if (visit[i] || visit2[i - row + n] || visit3[i + row])
            {
                continue;
            }
            visit[i] = visit2[i - row + n] = visit3[i + row] = 1;
            dfs(row + 1, n);
            visit[i] = visit2[i - row + n] = visit3[i + row] = 0;
        }
    }
};
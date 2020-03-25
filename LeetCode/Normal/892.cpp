#include <bits/stdc++.h>
#include <math.h>
using namespace std;

class Solution
{
public:
    int surfaceArea(vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                ans += grid[i][j] * 6; // 一个的表面积为6
                if (grid[i][j] > 1)
                    ans -= (grid[i][j] - 1) * 2; // 当(i,j)上超过1个,要减去z轴重叠部分,两个之间面积为2
                if (i >= 1)
                    ans -= min(grid[i][j], grid[i - 1][j]) * 2;
                if (j >= 1)
                    ans -= min(grid[i][j], grid[i][j - 1]) * 2;
                // grid[i][j]会与grid[i - 1][j], grid[i][j - 1]有接触
                // 接触面个数为二者的最小,每一个接触面面积同样也是2,减去
            }
        }
        return ans;
    }
};
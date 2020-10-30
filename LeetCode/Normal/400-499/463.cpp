#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
        int len = 0;
        int w = grid.size();
        if (w)
        {
            int l = grid[0].size();
            for (int i = 0; i < w; i++)
            {
                for (int j = 0; j < l; j++)
                {
                    if (grid[i][j])
                    {
                        int c = 4;
                        for (int t = 0; t < 4; t++)
                        {
                            int x = i + dir[t][0];
                            int y = j + dir[t][1];
                            if (x < 0 || y < 0 || x >= w || y >= l)
                            {
                                continue;
                            }
                            if (grid[x][y])
                            {
                                c--;
                            }
                        }
                        len += c;
                    }
                }
            }
        }
        return len;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{1, 1}, {1, 1}};
    cout << s.islandPerimeter(grid);
    system("pause");
}
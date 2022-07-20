#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int row = grid.size(), lie = grid[0].size();
        k %= row * lie;

        k = row * lie - k;

        vector<int> temp;
        int j = 0, l = 0;

        for (int i = 0; i < row; i++)
            for (int j = 0; j < lie; j++)
                temp.push_back(grid[i][j]);

        for (int i = 0; i < row; i++)
            for (int j = 0; j < lie; j++)
            {
                grid[i][j] = temp[k++];
                if (k == row * lie)
                    k = 0;
            }

        return grid;
    }
};
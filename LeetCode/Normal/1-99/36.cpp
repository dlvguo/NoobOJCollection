#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<vector<int>> l(9, vector<int>(9, 0)), r(9, vector<int>(9, 0)), b(9, vector<int>(9, 0));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '1';
                    if (r[i][num] || l[j][num] || b[i / 3 * 3 + j / 3][num])
                        return false;
                    r[i][num] = 1;
                    l[j][num] = 1;
                    //映射九宫格
                    b[i / 3 * 3 + j / 3][num] = 1;
                }
            }
        }
        return true;
    }
};
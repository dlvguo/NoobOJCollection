#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool dfs(vector<vector<char>> &board, vector<vector<int>> &l, vector<vector<int>> &r, vector<vector<int>> &b, int x, int y)
    {
        if (y > 8)
            return true;
        if (x == 9)
            return dfs(board, l, r, b, 0, y + 1);
        if (board[x][y] != '.')
            return dfs(board, l, r, b, x + 1, y);
        //找到填充的数字
        for (int i = 0; i <= 8; i++)
        {
            if (r[x][i] == 1 || l[y][i] == 1 || b[x / 3 * 3 + y / 3][i] == 1)
                continue;
            r[x][i] = 1;
            l[y][i] = 1;
            b[x / 3 * 3 + y / 3][i] = 1;
            if (dfs(board, l, r, b, x + 1, y))
            {
                return true;
            }
            r[x][i] = 0;
            l[y][i] = 0;
            b[x / 3 * 3 + y / 3][i] = 0;
        }
        return false;
    }

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
                    r[i][num] = 1;
                    l[j][num] = 1;
                    //映射九宫格
                    b[i / 3 * 3 + j / 3][num] = 1;
                }
            }
        }
        return dfs(board, l, r, b, 0, 0);
    }
};
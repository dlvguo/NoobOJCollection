#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dir[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};

    int Figure(int x, int y, vector<vector<int>> &board)
    {
        int sum = 0;
        for (int i = 0; i < 8; i++)
        {
            int _x = x + dir[i][0], _y = dir[i][1] + y;
            if (_x < 0 || _y < 0 || _x >= board.size() || _y >= board[0].size())
                continue;
            if (board[_x][_y] > 0)
                sum++;
        }
        return sum;
    }

    void gameOfLife(vector<vector<int>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                int count = Figure(i, j, board);
                if (board[i][j] > 0)
                {
                    if (count < 2 || count > 3)
                    {
                        //说明要死了
                        board[i][j] = 2;
                    }
                }
                else if (count == 3)
                {
                    board[i][j] = -1;
                }
            }
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == -1)
                {
                    board[i][j] = 1;
                    continue;
                }
                if (board[i][j] == 2)
                    board[i][j] = 0;
            }
        }
    }
};
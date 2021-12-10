#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool validTicTacToe(vector<string> &board)
    {
        int xCount = 0, oCount = 0;
        for (string &row : board)
        {
            for (char c : row)
            {
                xCount = (c == 'X') ? (xCount + 1) : xCount;
                oCount = (c == 'O') ? (oCount + 1) : oCount;
            }
        }
        if (oCount != xCount && oCount != xCount - 1)
        {
            return false;
        }
        if (win(board, 'X') && oCount != xCount - 1)
        {
            return false;
        }
        if (win(board, 'O') && oCount != xCount)
        {
            return false;
        }
        return true;
    }

    bool win(vector<string> &board, char p)
    {
        for (int i = 0; i < 3; ++i)
        {
            if (p == board[i][0] && p == board[i][1] && p == board[i][2])
            {
                return true;
            }
            if (p == board[0][i] && p == board[1][i] && p == board[2][i])
            {
                return true;
            }
        }
        if (p == board[0][0] && p == board[1][1] && p == board[2][2])
        {
            return true;
        }
        if (p == board[0][2] && p == board[1][1] && p == board[2][0])
        {
            return true;
        }
        return false;
    }
};
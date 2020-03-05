#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

    bool dfs(vector<vector<char>> &board, string word, int x, int y, int num)
    {
        if (num == word.length())
            return true;
        for (int i = 0; i < 4; i++)
        {
            int _x = x + dir[i][0], _y = y + dir[i][1];
            if (_x < 0 || _y < 0 || _x == board.size() || _y == board[0].size() || board[_x][_y] == '\0' || board[_x][_y] != word[num])
                continue;
            char temp = board[_x][_y];
            board[_x][_y] = '\0';
            if (dfs(board, word, _x, _y, num + 1))
                return true;
            board[_x][_y] = temp;
        }
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int row = board.size();
        int lie = board[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < lie; j++)
            {
                if (word[0] == board[i][j])
                {
                    char temp = board[i][j];
                    board[i][j] = '\0';

                    if (dfs(board, word, i, j, 1))
                        return true;
                    board[i][j] = temp;
                }
            }
        }
        return false;
    }
};
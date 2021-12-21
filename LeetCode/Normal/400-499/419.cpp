#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countBattleships(vector<vector<char>> &board)
    {
        int row = board.size();
        int col = board[0].size();
        int ans = 0;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (board[i][j] == 'X')
                {
                    board[i][j] = '.';
                    for (int k = j + 1; k < col && board[i][k] == 'X'; ++k)
                    {
                        board[i][k] = '.';
                    }
                    for (int k = i + 1; k < row && board[k][j] == 'X'; ++k)
                    {
                        board[k][j] = '.';
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};
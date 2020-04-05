#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRookCaptures(vector<vector<char>> &board)
    {
        int x = -1, y;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 'R')
                {
                    x = i;
                    y = j;
                    break;
                }
            }
            if (x != -1)
                break;
        }
        int sum = 0;
        for (int i = x - 1; i >= 0; i--)
        {
            if (board[i][y] == 'p')
            {
                sum++;
                break;
            }
            else if (board[i][y] == 'B')
                break;
        }
        for (int i = x + 1; i < 8; i++)
        {
            if (board[i][y] == 'p')
            {
                sum++;
                break;
            }
            else if (board[i][y] == 'B')
                break;
        }

        for (int i = y - 1; i >= 0; i--)
        {
            if (board[x][i] == 'p')
            {
                sum++;
                break;
            }
            else if (board[x][i] == 'B')
                break;
        }

        for (int i = y + 1; i < 8; i--)
        {
            if (board[x][i] == 'p')
            {
                sum++;
                break;
            }
            else if (board[x][i] == 'B')
                break;
        }

        return sum;
    }
};
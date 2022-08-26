#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getMoves(int mask, int count, int n)
    {
        int ones = __builtin_popcount(mask);
        if (n & 1)
        {
            /* 如果 n 为奇数，则每一行中 1 与 0 的数目相差为 1，且满足相邻行交替 */
            if (abs(n - 2 * ones) != 1 || abs(n - 2 * count) != 1)
            {
                return -1;
            }
            if (ones == (n >> 1))
            {
                /* 偶数位变为 1 的最小交换次数 */
                return n / 2 - __builtin_popcount(mask & 0xAAAAAAAA);
            }
            else
            {
                /* 奇数位变为 1 的最小交换次数 */
                return (n + 1) / 2 - __builtin_popcount(mask & 0x55555555);
            }
        }
        else
        {
            /* 如果 n 为偶数，则每一行中 1 与 0 的数目相等，且满足相邻行交替 */
            if (ones != (n >> 1) || count != (n >> 1))
            {
                return -1;
            }
            /* 偶数位变为 1 的最小交换次数 */
            int count0 = n / 2 - __builtin_popcount(mask & 0xAAAAAAAA);
            /* 奇数位变为 1 的最小交换次数 */
            int count1 = n / 2 - __builtin_popcount(mask & 0x55555555);
            return min(count0, count1);
        }
    }

    int movesToChessboard(vector<vector<int>> &board)
    {
        int n = board.size();
        int rowMask = 0, colMask = 0;

        /* 检查棋盘的第一行与第一列 */
        for (int i = 0; i < n; i++)
        {
            rowMask |= (board[0][i] << i);
            colMask |= (board[i][0] << i);
        }
        int reverseRowMask = ((1 << n) - 1) ^ rowMask;
        int reverseColMask = ((1 << n) - 1) ^ colMask;
        int rowCnt = 0, colCnt = 0;
        for (int i = 0; i < n; i++)
        {
            int currRowMask = 0;
            int currColMask = 0;
            for (int j = 0; j < n; j++)
            {
                currRowMask |= (board[i][j] << j);
                currColMask |= (board[j][i] << j);
            }
            /* 检测每一行的状态是否合法 */
            if (currRowMask != rowMask && currRowMask != reverseRowMask)
            {
                return -1;
            }
            else if (currRowMask == rowMask)
            {
                /* 记录与第一行相同的行数 */
                rowCnt++;
            }
            /* 检测每一列的状态是否合法 */
            if (currColMask != colMask && currColMask != reverseColMask)
            {
                return -1;
            }
            else if (currColMask == colMask)
            {
                /* 记录与第一列相同的列数 */
                colCnt++;
            }
        }
        int rowMoves = getMoves(rowMask, rowCnt, n);
        int colMoves = getMoves(colMask, colCnt, n);
        return (rowMoves == -1 || colMoves == -1) ? -1 : (rowMoves + colMoves);
    }
};

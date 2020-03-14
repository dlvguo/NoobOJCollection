#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void PrintMariex(vector<vector<int>> &matrix, vector<int> &v, int row)
    {
        int endX = matrix.size() - row - 1, endY = matrix[0].size() - row - 1;
        //从左向右
        for (int i = row; i <= endY; i++)
        {
            v.push_back(matrix[row][i]);
        }

        //从右向下
        for (int i = row + 1; i <= endX; i++)
        {
            v.push_back(matrix[i][endY]);
        }

        //从右向左 避免同行
        if (row != endX)
            for (int i = endY - 1; i >= row; i--)
            {
                v.push_back(matrix[endX][i]);
            }
        //由下向上 避免同列
        if (row != endY)
            for (int i = endX - 1; i > row; i--)
            {
                v.push_back(matrix[i][row]);
            }
    }

    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0)
            return {};
        vector<int> nums;
        int row = 0, num = 0;
        while (matrix.size() > row * 2 && matrix[0].size() > 2 * row)
        {
            PrintMariex(matrix, nums, row);
            row++;
        }
        return nums;
    }
};

int main()
{
    Solution s1;
    vector<vector<int>> v = {{7}, {9}, {6}};
    s1.spiralOrder(v);
    system("pause");
}
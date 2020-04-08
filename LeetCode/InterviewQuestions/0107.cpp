#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {

        int len = matrix.size();
        // 对角线反转
        for (int i = 0; i < len; i++)
        {
            for (int j = i; j < len; j++)
            {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
        // 左右翻转
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len / 2; j++)
            {
                int t = matrix[i][j];
                matrix[i][j] = matrix[i][len - j - 1];
                matrix[i][len - j - 1] = t;
            }
        }
    }
};
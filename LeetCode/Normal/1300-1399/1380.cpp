#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int row = matrix.size(), col = matrix[0].size();
        vector<int> res;
        for (int i = 0; i < row; i++)
        {
            int _min = matrix[i][0], index = 0;
            for (int j = 1; j < col; j++)
            {
                if (_min > matrix[i][j])
                {
                    _min = matrix[i][j];
                    index = j;
                }
            }
            bool tag = true;
            for (int l = 0; l < row; l++)
            {
                if (matrix[l][index] > _min)
                {
                    tag = false;
                    break;
                }
            }
            if (tag)
                res.push_back(_min);
        }
        return res;
    }
};
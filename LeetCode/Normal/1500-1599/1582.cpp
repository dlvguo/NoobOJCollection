#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<int> rowsSum(m);
        vector<int> colsSum(n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                rowsSum[i] += mat[i][j];
                colsSum[j] += mat[i][j];
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1 && rowsSum[i] == 1 && colsSum[j] == 1)
                {
                    res++;
                }
            }
        }
        return res;
    }
};
